/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:35 by hyko              #+#    #+#             */
/*   Updated: 2022/07/01 14:59:20 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

typedef struct s_stack
{
	t_list	*top;
	t_list	*btm;
	int		size;
}	t_stack;

/* checker_bonus.c */
void		exe_command(t_stack *stack_a, t_stack *stack_b, char *cmd);
void		check_is_sorted(t_stack *stack_a, t_stack *stack_b);
void		parsing(int argc, char **argv, t_stack *stack, int i);

/* ft_split.c */
int			word_count(char const *s, char c);
int			word_len(char const *s, char c);
char		**ft_split(char const *s, char c);

/* get_next_line_utils.c */
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const	*s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

/* get_next_line.c */
char		*get_next_line(int fd);
int			gnl_find_newline(char *read_line);
char		*gnl_read_line(int fd);
char		*gnl_expand_backup(char *backup, int fd);
char		*gnl_cut_backup(char *backup, char *return_line);

/* operation_push.c */
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

/* operation_reverse_rotate.c */
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

/* operation_rotate.c */
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

/* operation_swap.c */
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);

/* parsing.c */
void		is_num(char *str);
void		check_duplicate_and_indexing(t_stack *stack, int data);

/* push_swap_utils.c */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
long long	ft_atol(const char *str);
void		print_error(void);
int			ft_strcmp(char *s1, char *s2);

/* stack.c */
void		stack_element_init(t_stack *stack);
t_stack		*stack_init(void);
void		insert_first_node(t_stack *stack, int data);
void		push(t_stack *stack, int data);
t_list		*pop(t_stack *stack);

#endif