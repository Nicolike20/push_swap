/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:28:04 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/27 21:55:22 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(char **argv, int check)
{
	int		i;
	int		j;
	size_t	n;

	i = check;
	while (argv[++i])
	{
		j = i;
		if (ft_atoi(argv[i]) >= 2147483648 || ft_atoi(argv[i]) < -2147483648)
			return (1);
		while (argv[++j])
		{
			n = ft_strlen(argv[i]);
			if (ft_strlen(argv[j]) > n)
				n = ft_strlen(argv[j]);
			if (ft_strncmp(argv[i], argv[j], n) == 0)
				return (1);
		}
	}
	return (0);
}

int	check_digits(char **argv, int check)
{
	int	i;
	int	j;

	i = check;
	while (argv[++i])
	{
		j = -1;
		if (argv[i][0] == '\0')
			return (1);
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			return (1);
		if (argv[i][0] == '-')
			j++;
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
		}
	}
	return (0);
}

int	is_sorted(t_list *stack_a, int check)
{
	t_list	aux;
	int		prev;

	aux = *stack_a;
	prev = 0;
	while (aux.next != NULL)
	{
		if (prev == 0 && check == 0)
		{
			prev = *(int *)aux.content;
			check = 1;
		}
		else
		{
			if (prev > *(int *)aux.content)
				return (1);
			else
				prev = *(int *)aux.content;
		}
		aux = *aux.next;
	}
	if (prev > *(int *)aux.content)
		return (1);
	return (0);
}

void	free_arr(char **tmp, int argc)
{
	while (argc--)
		free(tmp[argc]);
	free(tmp);
}
