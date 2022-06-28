/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:41:49 by hyko              #+#    #+#             */
/*   Updated: 2022/06/28 21:53:16 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	if (stack->top == NULL)
	{
		printf("NULL\n");
		return ;
	}
	t_list *curr;
	// printf("d  i\n");
	// printf("-  -\n");
	// curr = stack->top;
	// while (curr != stack->btm)
	// {
	// 	printf("%d  %d\n", curr->data, curr->index);
	// 	curr = curr->next;
	// }
	// printf("%d  %d\n", curr->data, curr->index);
	int i = 0;
	curr = stack->top;	
	while (curr != stack->btm)
	{
		i = curr->index;
		while (i > 0)
		{
			printf("|");
			i--;
		}
		printf("\n");
		curr = curr->next;
	}
	i = curr->index;
	while (i > 0)
	{
		printf("|");
		i--;
	}
	printf("\n");
}

// void	print_error_msg(char *str)
// {
// 	printf("%s\n", str);
// 	exit(0);
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;
	int		data;
	int		i;
	int		j;

	stack_a = stack_init();
	stack_b = stack_init();
	if (argc < 2)
		print_error_msg("error\nneed data");
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			is_num(tmp[j]);
			data = ft_atol(tmp[j]);
			if (data < INT_MIN || data > INT_MAX)
				print_error_msg("error\nint");
			if (i == 1 && j == 0)
				insert_first_node(stack_a, data);
			else
				push(stack_a, data);
			check_duplicate_and_indexing(stack_a, data);
			stack_a->size++;
			free(tmp[j]);
			j++;
		}
		free(tmp);
		i++;
	}
	if (stack_a->size < 6)
	{
		less_than_five(stack_a, stack_b);
		// printf("a : \n");
		// print_stack(stack_a);
		// printf("b : \n");
		// print_stack(stack_b);
		exit(0);
	}
	a_to_b(stack_a, stack_b);
	// printf("\n");
	// print_stack(stack_a);
	// printf("\n");
	// print_stack(stack_b);
	b_to_a(stack_a, stack_b);
	system("leaks a.out");
	return (0);
}