/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_five_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:59:39 by hyko              #+#    #+#             */
/*   Updated: 2022/06/30 16:55:02 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	find_num_and_push(t_stack *stack_a, t_stack *stack_b, int num)
{
	t_list	*curr;
	int		cnt;

	while (stack_a->size - num > 3)
	{
		curr = stack_a->top;
		cnt = 0;
		while (curr->index != num)
		{
			curr = curr->next;
			cnt++;
		}
		if (cnt <= (stack_a->size - num) / 2)
		{
			while (stack_a->top->index != num)
				ra(stack_a);
		}
		else if (cnt > (stack_a->size - num) / 2)
		{
			while (stack_a->top->index != num)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		num++;
	}
}

void	sort_three_node(t_stack *stack_a, int size)
{
	if (stack_a->top->index == size - 3)
	{
		if (stack_a->top->next->index == size - 1)
		{
			sa(stack_a);
			ra(stack_a);
		}	
	}
	else if (stack_a->top->index == size - 2)
	{
		if (stack_a->top->next->index == size - 3)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else if (stack_a->top->index == size - 1)
	{
		if (stack_a->top->next->index == size - 3)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	less_than_five(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	num;

	size = stack_a->size;
	num = 0;
	if (size == 2 && stack_a->top->index == 1)
		sa(stack_a);
	if (size == 3)
		sort_three_node(stack_a, size);
	if (size == 4)
	{
		find_num_and_push(stack_a, stack_b, num);
		sort_three_node(stack_a, size);
		pa(stack_a, stack_b);
	}
	if (size == 5)
	{
		find_num_and_push(stack_a, stack_b, num);
		sort_three_node(stack_a, size);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	exit(0);
}
