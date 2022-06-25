/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:59:23 by hyko              #+#    #+#             */
/*   Updated: 2022/06/25 16:19:11 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "pa\n", 3);
	t_list	*node;

	if (stack_b->top != NULL)
	{
		node = pop(stack_b);
		if (stack_a->top == NULL)
		{
			node->prev = node;
			node->next = node;
			stack_a->top = node;
			stack_a->btm = node;
		}
		else
		{
			node->next = stack_a->top;
			node->prev = stack_a->btm;
			stack_a->btm->next = node;
			stack_a->top->prev = node;
			stack_a->top = node;
		}
	}
	if (stack_a->top == stack_b->top)
	{
		stack_b->top = NULL;
		stack_b->btm = NULL;
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "pb\n", 3);
	t_list	*node;
	
	if (stack_a->top != NULL)
	{
		node = pop(stack_a);
		if (stack_b->top == NULL)
		{
			node->prev = node;
			node->next = node;
			stack_b->top = node;
			stack_b->btm = node;
		}
		else
		{
			node->next = stack_b->top;
			node->prev = stack_b->btm;
			stack_b->btm->next = node;
			stack_b->top->prev = node;
			stack_b->top = node;
		}	
	}
	if (stack_a->top == stack_b->top)
	{
		stack_a->top = NULL;
		stack_a->btm = NULL;
	}
}
