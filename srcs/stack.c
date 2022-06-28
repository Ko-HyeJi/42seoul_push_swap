/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:30:23 by hyko              #+#    #+#             */
/*   Updated: 2022/06/28 21:49:47 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_element_init(t_stack *stack)
{
	stack->top = NULL;
	stack->btm = NULL;
}

t_stack	*stack_init(void)
{
	t_stack	*stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	//stack->top = (t_list *)malloc(sizeof(t_list));
	//stack->btm = (t_list *)malloc(sizeof(t_list));
	stack_element_init(stack);
	return (stack);
}

void	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
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

	curr = stack->top;
	while (curr->next != stack->top)
	{
		if (curr->data == data)
			print_error_msg("error\ncheck_duplicate");
		else if (curr->data < data)
			stack->btm->index++;
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
	stack->top = node;
	stack->btm = node;
}

void	push(t_stack *stack, int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		print_error_msg("error\npush");
	node->data = data;
	node->next = stack->top;
	node->prev = stack->btm;
	stack->top->prev = node;
	stack->btm->next = node;
	stack->btm = node;
}

t_list	*pop(t_stack *stack)
{
	t_list	*ret;

	ret = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = stack->btm;
	stack->btm->next = stack->top;
	return (ret);
}
