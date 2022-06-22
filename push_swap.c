/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:41:49 by hyko              #+#    #+#             */
/*   Updated: 2022/06/22 17:21:07 by hyko             ###   ########.fr       */
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
			print_error_msg("error\nis_num\n");
		i++;
	}
}

void	check_duplicate(t_stack *stack_a, int value)
{
	t_list	*search;
	int		index;

	search = stack_a->head;
	printf("search->value : %d\n", search->value);
	while (search->prev != stack_a->head)
	{
		if (search->value == value)
			print_error_msg("error\ncheck_duplicate\n");
		search = search->next;
	}
}

void	push(int value, t_stack *stack_a)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		print_error_msg("error\npush\n");
	new->value = value;
	new->prev = stack_a->curr;
	new->next = stack_a->head;
	printf("new->value : %d\n", new->value);
	stack_a->head->prev = new;
	stack_a->curr->next = new;
	stack_a->curr = new;
}

void	add_index(t_stack *stack_a)
{
	
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		value;
	int		i;
	int		j;
	t_list	*head;
	t_list	*curr;	
	
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	head = (t_list *)malloc(sizeof(t_list));
	curr = (t_list *)malloc(sizeof(t_list));
	//printf("head : %d\n", head->value);
	//printf("curr : %d\n", curr->value);	
	stack_a->head = head;
	stack_a->curr = curr;
	//printf("head : %d\n", stack_a->head->value);
	//printf("curr : %d\n", stack_a->curr->value);
	i = 1;
	while (i <argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			is_num(tmp[j]);
			value = ft_atol(tmp[j]);
			if (value < -2147483648 || value > 2147483647)
				print_error_msg("error\nint\n");
			//printf("value : %d\n", value);
			push(value, stack_a);
			//check_duplicate(stack_a, value);
			j++;
		}
		i++;
	}
	return (0);
}
