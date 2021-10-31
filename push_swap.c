/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:41:11 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/27 21:51:45 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*map_list(t_list *stack_a)
{
	t_list	*head_a;
	t_list	*aux;
	int		index;

	head_a = stack_a;
	while (stack_a != NULL)
	{
		index = 0;
		aux = head_a;
		while (aux != NULL)
		{
			if (*(int *)stack_a->content > *(int *)aux->content)
				index++;
			aux = aux->next;
		}
		stack_a->index = index;
		stack_a->s_check = 0;
		stack_a = stack_a->next;
	}
	return (head_a);
}

static t_list	*push_swap(t_list *stack_a, t_list *stack_b, int argc)
{
	int	chunk_size;
	int	ls;

	ls = ft_lstsize(stack_a);
	chunk_size = (ls / 13) + 22;
	stack_a = map_list(stack_a);
	if (is_sorted(stack_a, 0))
	{
		if (argc - 1 == 2)
			stack_a = sa(stack_a, 0);
		else if (argc - 1 == 3)
			stack_a = sort_three(stack_a);
		else if (argc - 1 == 4)
			stack_a = sort_four(stack_a, stack_b);
		else if (argc - 1 == 5)
			stack_a = sort_five(stack_a, stack_b);
		else
		{
			stack_a = break_chunks(stack_a, stack_b, chunk_size, ls);
		}
	}
	return (stack_a);
}

static void	parse_list(char **argv, int i, int argc, int is_single_arg)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*tmp;

	stack_a = NULL;
	stack_b = NULL;
	while (++i < argc)
	{
		tmp = (int *)malloc(sizeof(int));
		if (!tmp)
			return ;
		*tmp = (int)ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(tmp));
	}
	if (is_single_arg)
		argc++;
	stack_a = push_swap(stack_a, stack_b, argc);
	if (is_single_arg)
	{
		while (i--)
			free(argv[i]);
		free(argv);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}

static int	split_len(char **tmp)
{
	int	res;

	res = 0;
	while (tmp[res])
		res++;
	return (res);
}

/*void	leaks(void)
{
	system("leaks a.out");
}*/
/*	atexit(leaks);*/
int	main(int argc, char **argv)
{
	int		i;
	char	**tmp;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		i = 0;
		argc = split_len(tmp);
		if (argc <= 0 || check_digits(tmp, -1) || check_doubles(tmp, -1))
		{
			free_arr(tmp, argc);
			return (write(1, "Error\n", 6));
		}
		parse_list(tmp, -1, argc, 1);
	}
	else
	{
		if (check_digits(argv, 0) || check_doubles(argv, 0))
			return (write(1, "Error\n", 6));
		parse_list(argv, 0, argc, 0);
	}
	return (0);
}
