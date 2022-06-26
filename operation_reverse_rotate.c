/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:59:26 by hyko              #+#    #+#             */
/*   Updated: 2022/06/26 22:14:40 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	write(1, "rra\n", 4);
	if (stack_a->top != NULL)
	{
		stack_a->top = stack_a->btm;
		stack_a->btm = stack_a->btm->prev;
	}
}

void	rrb(t_stack *stack_b)
{
	write(1, "rrb\n", 4);
	if (stack_b->top != NULL)
	{
		stack_b->top = stack_b->btm;
		stack_b->btm = stack_b->btm->prev;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rrr\n", 4);
	if (stack_a->top != NULL)
	{
		stack_a->top = stack_a->btm;
		stack_a->btm = stack_a->btm->prev;
	}
	if (stack_b->top != NULL)
	{
		stack_b->top = stack_b->btm;
		stack_b->btm = stack_b->btm->prev;
	}
}
