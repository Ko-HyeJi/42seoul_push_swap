/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:41:49 by hyko              #+#    #+#             */
/*   Updated: 2022/06/23 22:19:01 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_msg(char *str)
{
	printf("%s\n", str);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;
	int		value;
	int		i;
	int		j;

	stack_a = stack_init();
	stack_b = stack_init();

	if (argc < 2)
		print_error_msg("error\nneed value");
	
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
				push(stack_a, value);
			check_duplicate_and_indexing(stack_a, value);
			stack_a->size++;
			j++;
		}
		free(tmp);
		i++;
	}
	return (0);
}
