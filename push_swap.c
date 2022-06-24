/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:41:49 by hyko              #+#    #+#             */
/*   Updated: 2022/06/24 17:51:03 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	if (stack->top == NULL)
	{
		printf("NULL\n");
		return ;
	}
	printf("d  i\n");
	printf("-  -\n");
	t_list *curr;
	curr = stack->top;
	while (stack->size > 0)
	{
		printf("%d  %d\n", curr->data, curr->index);
		curr = curr->next;
		stack->size--;
	}
}

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
			j++;
		}
		free(tmp);
		i++;
	}
	// printf("top : %d\n", stack_a->top->data);
	// printf("btm : %d\n", stack_a->btm->data);	
	// printf("top->prev : %d\n", stack_a->top->prev->data);
	// printf("top->next : %d\n", stack_a->top->next->data);
	// printf("btm->prev : %d\n", stack_a->btm->prev->data);
	// printf("btm->next : %d\n", stack_a->btm->next->data);
	//pb(stack_a, stack_b);
	printf("stack_a : \n");
	print_stack(stack_a);
	printf("\n");
	printf("stack_b : \n");
	print_stack(stack_b);
	return (0);
}
