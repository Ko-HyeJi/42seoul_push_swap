/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:41:49 by hyko              #+#    #+#             */
/*   Updated: 2022/06/23 22:06:47 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_msg(char *str)
{
	printf("%s\n", str);
	exit(0);
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

void	push(int value, t_stack *stack)
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		value;
	int		i;
	int		j;

	if (argc < 2)
		print_error_msg("error\nneed value");
	
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_a->head = (t_list *)malloc(sizeof(t_list));
	stack_a->curr = (t_list *)malloc(sizeof(t_list));
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			is_num(tmp[j]);
			value = ft_atol(tmp[j]);
			if (value < INT_MIN || value > INT_MAX)
				print_error_msg("error\nint");
			if (i == 1 && j == 0)
				insert_first_node(stack_a, value);
			else
				push(value, stack_a);
			check_duplicate_and_indexing(stack_a, value);
			stack_a->size++;
			j++;
		}
		i++;
	}
	free(tmp);
	return (0);
}
