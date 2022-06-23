/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:35 by hyko              #+#    #+#             */
/*   Updated: 2022/06/23 22:19:23 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef	struct s_stack
{
	t_list	*head;
	t_list	*curr;
	int		size;
}	t_stack;


size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
static char	**ft_malloc_error(char **str);
int	word_count(char const *s, char c);
int	word_len(char const *s, char c);
char	**ft_split(char const *s, char c);
long long	ft_atol(const char *str);

/* push_swap.c */
void	print_error_msg(char *str);

/* stack.c */
t_stack	*stack_init(void);
void	is_num(char *str);
void	check_duplicate_and_indexing(t_stack *stack, int value);
void	insert_first_node(t_stack *stack, int value);
void	push(t_stack *stack, int value);
//void	pop(t_stack *stack);

#endif