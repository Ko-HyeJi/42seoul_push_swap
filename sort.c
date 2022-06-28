/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:25:42 by hyko              #+#    #+#             */
/*   Updated: 2022/06/28 15:31:00 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_direction(t_stack *stack_a, int num, int chunk)
{
	t_list	*curr;
	int		cnt;
	int		flag;
	
	cnt = 0;
	flag = 0;
	curr = stack_a->top;
	while (curr->index > num + chunk)
	{
		curr = curr->next;
		cnt++;
	}
	if (cnt > (stack_a->size - num) / 2)
		flag = 1;
	return (flag);
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	num;
	int	chunk;
	int	size;
	int	flag;
	
	size = stack_a->size;
	num = 0;
	chunk = (0.000000053 * size * size) + (0.03 * size) + 14.5;
	while (stack_a->top != NULL)
	{
		flag = check_direction(stack_a, num, chunk);
		if (stack_a->top->index < num)
		{
			pb(stack_a, stack_b);
			num++;
		}
		else if (stack_a->top->index >= num && stack_a->top->index <= num + chunk)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			num++;
		}
		else if (stack_a->top->index > num + chunk)
		{
			if (flag == 0)
				ra(stack_a);
			else if (flag == 1)
				rra(stack_a);
		}
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;
	int		num;
	int		cnt;
	
	num = stack_a->size - 1;
	while (stack_b->top != NULL)
	{
		curr = stack_b->top;
		cnt = 0;
		while (curr->index != num)
		{
			curr = curr->next;
			cnt++;
		}
		if (cnt <= num / 2)
		{
			while (stack_b->top->index != num)
				rb(stack_b);
		}
		else if (cnt > num / 2)
		{
			while (stack_b->top->index != num)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		num--;
	}
}

void	find_num_and_push(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;
	int		cnt;
	int		num;
	
	num = 0;
	while (stack_a->size - num > 3)
	{
		curr = stack_a->top;
		cnt = 0;
		while (curr->index != num)
		{
			curr = curr->next;
			cnt++;
		}
		if (cnt <= (stack_a->size - num) / 2)
		{
			while (stack_a->top->index != num)
				ra(stack_a);
		}
		else if (cnt > (stack_a->size - num) / 2)
		{
			while (stack_a->top->index != num)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		num++;
	}
}

void	sort_three_node(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	
	size = stack_a->size;
	if (stack_a->top->index == size - 3)
	{
		if (stack_a->top->next->index == size - 1)
		{
			sa(stack_a);
			ra(stack_a);
		}	
	}
	else if (stack_a->top->index == size - 2)
	{
		if (stack_a->top->next->index == size - 3)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else if (stack_a->top->index == size - 1)
	{
		if (stack_a->top->next->index == size - 3)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	less_than_five(t_stack *stack_a, t_stack *stack_b)
{
	// if (stack_a->size == 1)
	// 	return ;
	if (stack_a->size == 2 && stack_a->top->index == 1)
		sa(stack_a);
	if (stack_a->size == 3)
		sort_three_node(stack_a, stack_b);
	if (stack_a->size == 4)
	{
		find_num_and_push(stack_a, stack_b);
		sort_three_node(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	if (stack_a->size == 5)
	{
		find_num_and_push(stack_a, stack_b);
		sort_three_node(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}




// void	less_than_five(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_list	*curr;
// 	int		num;
// 	int		cnt;
	
// 	num = 0;
// 	while (stack_a->size - num > 2)
// 	{
// 		curr = stack_a->top;
// 		cnt = 0;
// 		while (curr->index != num)
// 		{
// 			curr = curr->next;
// 			cnt++;
// 		}
// 		if (cnt <= (stack_a->size - num) / 2)
// 		{
// 			while (stack_a->top->index != num)
// 				ra(stack_a);
// 		}
// 		else if (cnt > (stack_a->size - num) / 2)
// 		{
// 			while (stack_a->top->index != num)
// 				rra(stack_a);
// 		}
// 		pb(stack_a, stack_b);
// 		num++;
// 	}
// 	// printf("stack_a->top->index : %d\n", stack_a->top->index);
// 	// printf("stack_a->size : %d\n", stack_a->size);
// 	if (stack_a->top->index == stack_a->size - 1)
// 		sa(stack_a);
// 	while (stack_b->top != NULL)
// 		pa(stack_a, stack_b);
// }
