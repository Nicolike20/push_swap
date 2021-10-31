/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:36:23 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/27 18:39:04 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_three(t_list *stack_a)
{
	int	arr[3];

	arr[0] = *(int *)stack_a->content;
	arr[1] = *(int *)stack_a->next->content;
	arr[2] = *(int *)stack_a->next->next->content;
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
	{
		stack_a = rra(stack_a, 0);
		stack_a = sa(stack_a, 0);
	}
	else if (arr[0] > arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
		stack_a = sa(stack_a, 0);
	else if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
		stack_a = rra(stack_a, 0);
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		stack_a = ra(stack_a, 0);
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
	{
		stack_a = sa(stack_a, 0);
		stack_a = rra(stack_a, 0);
	}
	return (stack_a);
}

t_list	*sort_four(t_list *stack_a, t_list *stack_b)
{
	while (stack_a)
	{
		if (stack_a->index == 0)
		{
			stack_a = pb(stack_a, &stack_b, 0);
			break ;
		}
		stack_a = rra(stack_a, 0);
	}
	stack_a = sort_three(stack_a);
	stack_b = pa(stack_b, &stack_a, 0);
	return (stack_a);
}

t_list	*sort_five(t_list *stack_a, t_list *stack_b)
{
	int	p_count;

	p_count = 0;
	while (stack_a)
	{
		if (stack_a->index == 1 || stack_a->index == 0)
		{
			stack_a = pb(stack_a, &stack_b, 0);
			p_count++;
		}
		if (p_count == 2)
			break ;
		stack_a = rra(stack_a, 0);
	}
	stack_a = sort_three(stack_a);
	if (*(int *)stack_b->content < *(int *)stack_b->next->content)
		stack_b = sb(stack_b, 0);
	stack_b = pa(stack_b, &stack_a, 0);
	stack_b = pa(stack_b, &stack_a, 0);
	return (stack_a);
}

int	rotate_bot(int i, int count, t_list **aux_b)
{
	count = i - count;
	if ((*aux_b)->s_check == 1)
		count--;
	while (count-- >= 0)
	{
		*aux_b = rrb(*aux_b, 0);
		if ((*aux_b)->index == i - 1 && (*aux_b)->s_check != 1)
		{
			(*aux_b)->s_check = 1;
			return (1);
		}
	}
	return (0);
}

int	rotate_top(int i, int count, t_list **aux_b)
{
	while (count--)
	{
		*aux_b = rb(*aux_b, 0);
		if ((*aux_b)->index == i - 1 && (*aux_b)->s_check != 1)
		{
			(*aux_b)->s_check = 1;
			return (1);
		}
	}
	return (0);
}
