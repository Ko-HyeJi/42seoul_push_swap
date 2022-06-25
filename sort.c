/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:25:42 by hyko              #+#    #+#             */
/*   Updated: 2022/06/25 21:02:22 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	num;
	int	chunk;
	int	size;
	
	size = stack_a->size;
	num = 0;
	chunk = (0.000000053 * size * size) + (0.03 * size) + 14.5;
	//printf("chunk : %d\n", chunk);
	while (stack_a->top != NULL)
	{
		if (stack_a->top->index < num)
			pb(stack_a, stack_b);
		else if (stack_a->top->index >= num && stack_a->top->index <= num + chunk)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if (stack_a->top->index > num + chunk)
		{
			ra(stack_a);
		}
		num++;
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	num;
	
	num = stack_a->size - 1;
	// printf("%d\n", num);
	while (stack_b->top != NULL)
	{
		if (stack_b->top->index < stack_b->btm->index)
			rrb(stack_b);
		if (stack_b->top->index == num)
		{
			pa(stack_a, stack_b);
			num--;
		}
	}
}
