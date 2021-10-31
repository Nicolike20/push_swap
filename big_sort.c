/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:03:04 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/27 18:38:21 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_next_b(t_list *head_b, t_list *aux_b, int i)
{
	int	count;

	count = 0;
	while (aux_b->index != i)
	{
		aux_b = aux_b->next;
		count++;
	}
	aux_b = head_b;
	if (count >= (i / 2))
	{
		if (rotate_bot(i, count, &aux_b))
			return (aux_b);
	}
	else
	{
		if (rotate_top(i, count, &aux_b))
			return (aux_b);
	}
	return (aux_b);
}

static int	find_prev(t_list *head_b, t_list **stack_a, t_list **aux_b, int i)
{
	*aux_b = pa(*aux_b, stack_a, 0);
	head_b = *aux_b;
	(*aux_b)->s_check = 1;
	*aux_b = find_next_b(*aux_b, head_b, i);
	*aux_b = pa(*aux_b, stack_a, 0);
	*stack_a = sa(*stack_a, 0);
	i--;
	return (i);
}

static t_list	*sort_chunks(t_list *stack_a, t_list **stack_b, int ls)
{
	t_list	*head_b;
	t_list	*aux_b;
	int		i;

	aux_b = *stack_b;
	i = ls;
	head_b = aux_b;
	while (--i >= 0)
	{
		if (aux_b->index != i)
			aux_b = find_next_b(head_b, aux_b, i);
		if (aux_b->index == i)
			aux_b = pa(aux_b, &stack_a, 0);
		else if (aux_b->index == i - 1 && aux_b->s_check == 1)
			i = find_prev(head_b, &stack_a, &aux_b, i);
		head_b = aux_b;
		while (aux_b)
		{
			aux_b->s_check = 0;
			aux_b = aux_b->next;
		}
		aux_b = head_b;
	}
	return (stack_a);
}

static void	real_breaker(int chunk_size, t_list **stack_a,
		t_list **stack_b, t_chunk_vars *vars)
{
	if ((*stack_a)->index < chunk_size && ++(*vars).top_count)
	{
		if ((*stack_a)->index < (*vars).div_count)
			(*vars).do_rb = 1;
		(*stack_a) = pb((*stack_a), stack_b, 0);
		if ((*vars).do_rb && ((*vars).top_count > 1
				|| chunk_size != (*vars).aux))
			(*stack_b) = rb((*stack_b), 0);
	}
}

t_list	*break_chunks(t_list *stack_a, t_list *stack_b, int chunk_size, int ls)
{
	t_chunk_vars	vars;

	vars.top_count = 0;
	vars.aux = chunk_size;
	vars.div_count = chunk_size / 2;
	while (stack_a)
	{
		vars.do_rb = 0;
		real_breaker(chunk_size, &stack_a, &stack_b, &vars);
		if (vars.top_count == vars.aux)
		{
			if (chunk_size == ls)
				break ;
			vars.div_count += vars.aux;
			chunk_size += vars.aux;
			vars.top_count = 0;
		}
		vars.head_a = stack_a;
		if (ft_lstsize(stack_a) > 1 && stack_a->index >= chunk_size)
			stack_a = ra(stack_a, 0);
	}
	stack_b = map_list(stack_b);
	stack_a = sort_chunks(stack_a, &stack_b, ft_lstsize(stack_b));
	return (stack_a);
}
