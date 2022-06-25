/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:59:30 by hyko              #+#    #+#             */
/*   Updated: 2022/06/25 16:23:03 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	write(1, "ra\n", 3);
	if (stack_a->top != NULL)
	{
		stack_a->btm = stack_a->top;
		stack_a->top = stack_a->top->next;
	}
}

void	rb(t_stack *stack_b)
{
	write(1, "rb\n", 3);
	if (stack_b->top != NULL)
	{
		stack_b->btm = stack_b->top;
		stack_b->top = stack_b->top->next;
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rr\n", 3);
	if (stack_a->top != NULL)
	{
		stack_a->btm = stack_a->top;
		stack_a->top = stack_a->top->next;
	}
	if (stack_b->top != NULL)
	{
		stack_b->btm = stack_b->top;
		stack_b->top = stack_b->top->next;
	}
}
