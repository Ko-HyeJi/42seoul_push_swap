/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:27:22 by hyko              #+#    #+#             */
/*   Updated: 2022/06/30 19:46:30 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			print_error();
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
			print_error();
		else if (curr->data < data)
			stack->btm->index++;
		else if (curr->data > data)
			curr->index++;
		curr = curr->next;
	}
}
