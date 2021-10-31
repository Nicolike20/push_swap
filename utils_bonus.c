/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:57:07 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/29 18:09:38 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_inst_a(t_list **stack_a, t_list **stack_b, char *s, int checker)
{
	if (!ft_strncmp(s, "sa\n", 4))
		*stack_a = sa(*stack_a, 2);
	else if (!ft_strncmp(s, "ss\n", 4))
	{
		*stack_a = sa(*stack_a, 2);
		*stack_b = sb(*stack_b, 2);
	}
	else if (!ft_strncmp(s, "ra\n", 4))
		*stack_a = ra(*stack_a, 2);
	else if (!ft_strncmp(s, "rr\n", 4))
	{
		*stack_a = ra(*stack_a, 2);
		*stack_b = rb(*stack_b, 2);
	}
	else if (!ft_strncmp(s, "rra\n", 5))
		*stack_a = rra(*stack_a, 2);
	else if (!ft_strncmp(s, "rrr\n", 5))
	{
		*stack_a = rra(*stack_a, 2);
		*stack_b = rrb(*stack_b, 2);
	}
	else
		checker = 1;
	return (checker);
}

static void	do_inst_b(t_list **stack_a, t_list **stack_b, char *s, int checker)
{
	if (!ft_strncmp(s, "sb\n", 4))
		*stack_b = sb(*stack_b, 2);
	else if (!ft_strncmp(s, "rb\n", 4))
		*stack_b = rb(*stack_b, 2);
	else if (!ft_strncmp(s, "rrb\n", 5))
		*stack_b = rrb(*stack_b, 2);
	else if (!ft_strncmp(s, "pa\n", 4))
		*stack_b = pa(*stack_b, stack_a, 2);
	else if (!ft_strncmp(s, "pb\n", 4))
		*stack_a = pb(*stack_a, stack_b, 2);
	else if (checker == 1)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
}

void	read_inst(t_list *stack_a, t_list *stack_b)
{
	char	*s;
	int		checker;

	s = get_next_line(0);
	while (s)
	{
		checker = 0;
		checker = do_inst_a(&stack_a, &stack_b, s, checker);
		do_inst_b(&stack_a, &stack_b, s, checker);
		free(s);
		s = get_next_line(0);
	}
	free(s);
	if (stack_a != NULL && stack_b == NULL && !is_sorted(stack_a, 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
