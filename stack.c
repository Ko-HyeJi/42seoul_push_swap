/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:30:23 by hyko              #+#    #+#             */
/*   Updated: 2022/06/23 22:19:15 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = (t_list *)malloc(sizeof(t_list));
	stack->curr = (t_list *)malloc(sizeof(t_list));

	return (stack);
}

void	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			print_error_msg("error\nis_num");
		i++;
	}
}

void	check_duplicate_and_indexing(t_stack *stack, int value)
{
	t_list	*search;

	search = stack->head;
	while (search->next != stack->head)
	{
		if (search->value == value)
			print_error_msg("error\ncheck_duplicate");
		else if (search->value < value)
			stack->curr->index++;
		else if (search->value > value)
			search->index++;
		search = search->next;
	}
}

void	insert_first_node(t_stack *stack, int value)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		print_error_msg("error\nfirst_node");
	new->value = value;
	new->prev = new;
	new->next = new;
	stack->head = new;
	stack->curr = new;
}

void	push(t_stack *stack, int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		print_error_msg("error\npush");
	new->value = value;
	new->prev = stack->curr;
	new->next = stack->head;
	stack->head->prev = new;
	stack->curr->next = new;
	stack->curr = new;
}