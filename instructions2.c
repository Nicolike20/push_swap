/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:52:46 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/28 16:47:59 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sb(t_list *stack_b, int check)
{
	t_list	*aux;
	t_list	*head_b;

	head_b = stack_b;
	if (stack_b && stack_b->next)
	{
		stack_b = stack_b->next;
		aux = stack_b;
		head_b->next = stack_b->next;
		stack_b->next = head_b;
		head_b = aux;
		if (check == 0)
			write(1, "sb\n", 3);
	}
	return (head_b);
}

t_list	*pb(t_list *stack_a, t_list **stack_b, int check)
{
	t_list	*head_a;

	head_a = stack_a;
	if (stack_a)
	{
		ft_lstadd_front(stack_b, ft_lstnew(head_a->content));
		head_a = head_a->next;
		free(stack_a);
		if (check == 0)
			write(1, "pb\n", 3);
	}
	return (head_a);
}

t_list	*rb(t_list *stack_b, int check)
{
	t_list	*aux;
	t_list	*head_b;

	head_b = stack_b;
	if (stack_b && stack_b->next)
	{
		stack_b = stack_b->next;
		aux = ft_lstlast(stack_b);
		aux->next = head_b;
		head_b->next = NULL;
		if (check == 0)
			write(1, "rb\n", 3);
	}
	return (stack_b);
}

t_list	*rrb(t_list *stack_b, int check)
{
	t_list	*head_b;

	head_b = stack_b;
	if (stack_b && stack_b->next)
	{
		while (stack_b->next->next != NULL)
		{
			stack_b = stack_b->next;
		}
		stack_b->next->next = head_b;
		head_b = stack_b->next;
		stack_b->next = NULL;
		if (check == 0)
			write(1, "rrb\n", 4);
	}
	return (head_b);
}
