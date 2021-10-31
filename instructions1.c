/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:07:38 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/28 16:48:51 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sa(t_list *stack_a, int check)
{
	t_list	*aux;
	t_list	*head_a;

	head_a = stack_a;
	if (stack_a && stack_a->next)
	{
		stack_a = stack_a->next;
		aux = stack_a;
		head_a->next = stack_a->next;
		stack_a->next = head_a;
		head_a = aux;
		if (check == 0)
			write(1, "sa\n", 3);
		else if (check == 1)
			write(1, "ss\n", 3);
	}
	return (head_a);
}

t_list	*pa(t_list *stack_b, t_list **stack_a, int check)
{
	t_list	*head_b;

	head_b = stack_b;
	if (stack_b)
	{
		ft_lstadd_front(stack_a, ft_lstnew(head_b->content));
		head_b = head_b->next;
		free(stack_b);
		if (check == 0)
			write(1, "pa\n", 3);
	}
	return (head_b);
}

t_list	*ra(t_list *stack_a, int check)
{
	t_list	*aux;
	t_list	*head_a;

	head_a = stack_a;
	if (stack_a && stack_a->next)
	{
		stack_a = stack_a->next;
		aux = ft_lstlast(stack_a);
		aux->next = head_a;
		head_a->next = NULL;
		if (check == 0)
			write(1, "ra\n", 3);
		else if (check == 1)
			write(1, "rr\n", 3);
	}
	return (stack_a);
}

t_list	*rra(t_list *stack_a, int check)
{
	t_list	*head_a;

	head_a = stack_a;
	if (stack_a && stack_a->next)
	{
		while (stack_a->next->next != NULL)
		{
			stack_a = stack_a->next;
		}
		stack_a->next->next = head_a;
		head_a = stack_a->next;
		stack_a->next = NULL;
		if (check == 0)
			write(1, "rra\n", 4);
		else if (check == 1)
			write(1, "rrr\n", 4);
	}
	return (head_a);
}
