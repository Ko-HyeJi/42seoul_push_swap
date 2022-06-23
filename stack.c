/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:30:23 by hyko              #+#    #+#             */
/*   Updated: 2022/06/23 17:08:40 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = (t_list *)malloc(sizeof(t_list));
	stack->curr = (t_list *)malloc(sizeof(t_list));
}

void	push(int value, t_stack *stack)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		print_error_msg("error\npush\n");
	new->value = value;
	new->prev = stack->curr;
	new->next = stack->head;
	printf("new->value : %d\n", new->value);
	stack->head->prev = new;
	stack->curr->next = new;
	stack->curr = new;
}

void	pop(t_stack *stack)
{
	
}