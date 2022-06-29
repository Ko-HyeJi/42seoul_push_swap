/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:35 by hyko              #+#    #+#             */
/*   Updated: 2022/06/28 20:27:02 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define BUFFER_SIZE	100

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_list
{
	int				index;
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef	struct s_stack
{
	t_list	*top;
	t_list	*btm;
	int		size;
}	t_stack;

/* ft_split.c */
// static char	**ft_malloc_error(char **str);
int	word_count(char const *s, char c);
int	word_len(char const *s, char c);
char	**ft_split(char const *s, char c);

/* push_swap_utils.c */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
long long	ft_atol(const char *str);

/* push_swap.c */
void	print_error_msg(char *str);

/* stack.c */
t_stack	*stack_init(void);
void	stack_element_init(t_stack *stack);
void	is_num(char *str);
void	check_duplicate_and_indexing(t_stack *stack, int data);
void	insert_first_node(t_stack *stack, int data);
void	push(t_stack *stack, int data);
t_list	*pop(t_stack *stack);

/* operation.c */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* sort.c */
void	a_to_b(t_stack *stack_a, t_stack *stack_b);
void	b_to_a(t_stack *stack_a, t_stack *stack_b);
void	less_than_five(t_stack *stack_a, t_stack *stack_b);

/* get_next_line_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

/* get_next_line.c */
char	*get_next_line(int fd);
int		gnl_find_newline(char *read_line);
char	*gnl_read_line(int fd);
char	*gnl_expand_backup(char *backup, int fd);
char	*gnl_cut_backup(char *backup, char *return_line);
#endif