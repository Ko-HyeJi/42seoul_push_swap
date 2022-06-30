/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:25:42 by hyko              #+#    #+#             */
/*   Updated: 2022/06/30 16:26:04 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_direction(t_stack *stack_a, int num, int chunk)
{
	t_list	*curr;
	int		cnt;
	int		flag;

	cnt = 0;
	flag = 0;
	curr = stack_a->top;
	while (curr->index > num + chunk)
	{
		curr = curr->next;
		cnt++;
	}
	if (cnt > (stack_a->size - num) / 2)
		flag = 1;
	return (flag);
}

void	atob_next_step(t_stack *stack_a, t_stack *stack_b, int num, int chunk)
{
	int	flag;

	while (stack_a->top != NULL)
	{
		flag = check_direction(stack_a, num, chunk);
		if (stack_a->top->index < num)
		{
			pb(stack_a, stack_b);
			num++;
		}
		else if (
			stack_a->top->index >= num && stack_a->top->index <= num + chunk)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			num++;
		}
		else if (stack_a->top->index > num + chunk)
		{
			if (flag == 0)
				ra(stack_a);
			else if (flag == 1)
				rra(stack_a);
		}
	}
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	num;
	int	chunk;
	int	size;

	size = stack_a->size;
	num = 0;
	chunk = (0.000000053 * size * size) + (0.03 * size) + 14.5;
	atob_next_step(stack_a, stack_b, num, chunk);
}

void	btoa_next_step(t_stack *stack_a, t_stack *stack_b, int num)
{
	t_list	*curr;
	int		cnt;

	while (stack_b->top != NULL)
	{
		curr = stack_b->top;
		cnt = 0;
		while (curr->index != num)
		{
			curr = curr->next;
			cnt++;
		}
		if (cnt <= num / 2)
		{
			while (stack_b->top->index != num)
				rb(stack_b);
		}
		else if (cnt > num / 2)
		{
			while (stack_b->top->index != num)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		num--;
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;
	int		num;

	num = stack_a->size - 1;
	btoa_next_step(stack_a, stack_b, num);
}
