/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:35 by hyko              #+#    #+#             */
/*   Updated: 2022/07/03 16:03:31 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
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

/* ft_split.c */
int			word_count(char const *s, char c);
int			word_len(char const *s, char c);
char		**ft_split(char const *s, char c);

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
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
long long	ft_atol(const char *str);
void		print_error(void);

/* push_swap.c */
void		is_sorted(t_stack *stack);
void		parsing(t_stack *stack, char **tmp, int i, int j);

/* sort_less_than_five.c */
void		find_num_and_push(t_stack *stack_a, t_stack *stack_b, int num);
void		sort_three_node(t_stack *stack_a, int size);
void		less_than_five(t_stack *stack_a, t_stack *stack_b);

/* sort.c */
int			check_direction(t_stack *stack_a, int num, int chunk);
void		atob_next_step(
				t_stack *stack_a, t_stack *stack_b, int num, int chunk);
void		a_to_b(t_stack *stack_a, t_stack *stack_b);
void		btoa_next_step(t_stack *stack_a, t_stack *stack_b, int num);
void		b_to_a(t_stack *stack_a, t_stack *stack_b);

/* stack.c */
void		stack_element_init(t_stack *stack);
t_stack		*stack_init(void);
void		insert_first_node(t_stack *stack, int data);
void		push(t_stack *stack, int data);
t_list		*pop(t_stack *stack);

#endif