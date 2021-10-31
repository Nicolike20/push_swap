/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:14:04 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/28 15:21:21 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	aux_parse(char **argv, int i, int argc, int is_single_arg)
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
	read_inst(stack_a, stack_b);
	if (is_single_arg)
	{
		while (i--)
			free(argv[i]);
		free(argv);
	}
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
	system("leaks -q a.out");
}*/
/*atexit(leaks);*/
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
		aux_parse(tmp, -1, argc, 1);
	}
	else
	{
		if (check_digits(argv, 0) || check_doubles(argv, 0))
			return (write(1, "Error\n", 6));
		aux_parse(argv, 0, argc, 0);
	}
	return (0);
}
