/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:59:33 by hyko              #+#    #+#             */
/*   Updated: 2022/06/26 22:14:54 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
	int	tmp_d;
	int	tmp_i;

	tmp_d = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = tmp_d;
	tmp_i = stack_a->top->index;
	stack_a->top->index = stack_a->top->next->index;
	stack_a->top->next->index = tmp_i;
	tmp_d = stack_b->top->data;
	stack_b->top->data = stack_b->top->next->data;
	stack_b->top->next->data = tmp_d;
	tmp_i = stack_b->top->index;
	stack_b->top->index = stack_b->top->next->index;
	stack_b->top->next->index = tmp_i;	
}
