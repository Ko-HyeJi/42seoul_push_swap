/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:03 by hyko              #+#    #+#             */
/*   Updated: 2022/06/30 19:49:27 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	exe_command(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	if (cmd[0] == 's' && cmd[1] == 'a')
		sa(stack_a);
	else if (cmd[0] == 's' && cmd[1] == 'b')
		sb(stack_b);
	else if (cmd[0] == 'p' && cmd[1] == 'a')
		pa(stack_a, stack_b);
	else if (cmd[0] == 'p' && cmd[1] == 'b')
		pb(stack_a, stack_b);
	else if (cmd[0] == 'r' && cmd[1] == 'a')
		ra(stack_a);
	else if (cmd[0] == 'r' && cmd[1] == 'b')
		rb(stack_b);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'a')
		rra(stack_a);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b')
		rrb(stack_b);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r')
		rrr(stack_a, stack_b);
	else if (cmd[0] == 'r' && cmd[1] == 'r')
		rr(stack_a, stack_b);
	else
		exit(0);
}

void	check_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;

	if (stack_b->top != NULL)
		write(1, "KO\n", 3);
	curr = stack_a->top;
	while (curr != stack_a->btm)
	{
		if (curr->index > curr->next->index)
			write(1, "KO\n", 3);
		curr = curr->next;
	}
	write(1, "OK\n", 3);
	exit(0);
}

void	parsing(int argc, char **argv, t_stack *stack, int i)
{
	char		**tmp;
	int			j;
	long long	data;

	tmp = ft_split(argv[i], ' ');
	if (tmp[0] == NULL)
		print_error();
	j = 0;
	while (tmp[j])
	{
		is_num(tmp[j]);
		data = ft_atol(tmp[j]);
		if (data < INT_MIN || data > INT_MAX)
			print_error();
		if (i == 1 && j == 0)
			insert_first_node(stack, data);
		else
			push(stack, data);
		check_duplicate_and_indexing(stack, data);
		stack->size++;
		j++;
	}
	free(tmp);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	*cmd;

	stack_a = stack_init();
	stack_b = stack_init();
	if (argc < 2)
		print_error();
	i = 1;
	while (i < argc)
	{
		parsing(argc, argv, stack_a, i);
		i++;
	}
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			check_is_sorted(stack_a, stack_b);
		exe_command(stack_a, stack_b, cmd);
	}
	return (0);
}
