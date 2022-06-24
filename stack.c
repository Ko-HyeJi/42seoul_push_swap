/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:30:23 by hyko              #+#    #+#             */
/*   Updated: 2022/06/24 15:06:03 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->btm = (t_list *)malloc(sizeof(t_list));
	stack->top = (t_list *)malloc(sizeof(t_list));

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

void	check_duplicate_and_indexing(t_stack *stack, int data)
{
	t_list	*curr;

	curr = stack->btm;
	while (curr->next != stack->btm)
	{
		if (curr->data == data)
			print_error_msg("error\ncheck_duplicate");
		else if (curr->data < data)
			stack->top->index++;
		else if (curr->data > data)
			curr->index++;
		curr = curr->next;
	}
}

void	insert_first_node(t_stack *stack, int data)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		print_error_msg("error\nfirst_node");
	node->data = data;
	node->prev = node;
	node->next = node;
	stack->btm = node;
	stack->top = node;
}

void	push(t_stack *stack, int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		print_error_msg("error\npush");
	node->data = data;
	node->prev = stack->top;
	node->next = stack->btm;
	stack->btm->prev = node;
	stack->top->next = node;
	stack->top = node;
}

int	pop(t_stack *stack)
{
	int	ret;

	ret = stack->top->data;
	stack->top = stack->top->prev;
	stack->btm->prev = stack->top;
	stack->top->next = stack->btm;
	return (ret);
}
