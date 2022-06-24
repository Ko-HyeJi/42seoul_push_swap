/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:15:43 by hyko              #+#    #+#             */
/*   Updated: 2022/06/24 18:05:24 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp_d;
	int	tmp_i;

	tmp_d = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = tmp_d;
	tmp_i = stack_a->top->index;
	stack_a->top->index = stack_a->top->next->index;
	stack_a->top->next->index = tmp_i;
}

void	sb(t_stack *stack_b)
{
	int	tmp_d;
	int	tmp_i;

	tmp_d = stack_b->top->data;
	stack_b->top->data = stack_b->top->next->data;
	stack_b->top->next->data = tmp_d;
	tmp_i = stack_b->top->index;
	stack_b->top->index = stack_b->top->next->index;
	stack_b->top->next->index = tmp_i;	
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*node;

	node = pop(stack_b);
	if (stack_b->top != NULL)
	{
		if (stack_a->top == NULL)
		{
			
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
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top != NULL)
	{
		if (stack_b->top == NULL)
			insert_first_node(stack_b, pop(stack_a)->data);
		else
			push(stack_b, pop(stack_a)->data);
		
	}
}

void	ra(t_stack *stack_a)
{
	
}

void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack_a)
{
	
}

void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);