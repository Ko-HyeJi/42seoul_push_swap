/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:41:49 by hyko              #+#    #+#             */
/*   Updated: 2022/06/23 17:07:37 by hyko             ###   ########.fr       */
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
	/*while (search->prev != stack_a->head)
	{
		//printf("search->value : %d\n", search->value);
		//printf("head->value : %d\n", stack_a->head->value);
		if (search->value == value)
			print_error_msg("error\ncheck_duplicate\n");
		search = search->next;
	}*/
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

	stack_init(stack_a);
	i = 1;
	while (i <argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			is_num(tmp[j]);
			value = ft_atol(tmp[j]);
			if (value < INT_MIN || value > INT_MAX)
				print_error_msg("error\nint\n");
			push(value, stack_a);
			check_duplicate(stack_a, value);
			j++;
		}
		i++;
	}
	free(tmp);
		// printf("%d\n", stack_a->curr->prev->value);
		// printf("%d\n", stack_a->curr->value);
		// printf("%d\n", stack_a->curr->next->value);
		//printf("%d\n", stack_a->curr->next->value);
	return (0);
}
