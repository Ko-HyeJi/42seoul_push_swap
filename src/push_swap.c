/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:41:49 by hyko              #+#    #+#             */
/*   Updated: 2022/06/29 20:44:52 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_sorted(t_stack *stack)
{
	t_list	*curr;

	curr = stack->top;
	while (curr != stack->btm)
	{
		if (curr->index > curr->next->index)
			break ;
		curr = curr->next;
	}
	if (curr == stack->btm)
		exit(0);
}

void	parsing(t_stack *stack, char **tmp, int i, int j)
{
	long long	data;

	j = 0;
	while (tmp[j])
	{
		is_num(tmp[j]);
		data = ft_atol(tmp[j]);
		if (data < INT_MIN || data > INT_MAX)
			print_error_msg("error\nout of number range\n");
		if (i == 1 && j == 0)
			insert_first_node(stack, data);
		else
			push(stack, data);
		check_duplicate_and_indexing(stack, data);
		stack->size++;
		free(tmp[j]);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;
	int		i;
	int		j;

	if (argc < 2)
		print_error_msg("error\nneed data\n");
	stack_a = stack_init();
	stack_b = stack_init();
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		parsing(stack_a, tmp, i, j);
		free(tmp);
		i++;
	}
	is_sorted(stack_a);
	if (stack_a->size < 6)
		less_than_five(stack_a, stack_b);
	a_to_b(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
	return (0);
}
