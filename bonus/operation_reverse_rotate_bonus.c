/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:59:26 by hyko              #+#    #+#             */
/*   Updated: 2022/06/30 16:54:37 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	rra(t_stack *stack_a)
{
	if (stack_a->top != NULL)
	{
		stack_a->top = stack_a->btm;
		stack_a->btm = stack_a->btm->prev;
	}
}

void	rrb(t_stack *stack_b)
{
	if (stack_b->top != NULL)
	{
		stack_b->top = stack_b->btm;
		stack_b->btm = stack_b->btm->prev;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
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
