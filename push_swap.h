/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:14:47 by nortolan          #+#    #+#             */
/*   Updated: 2021/10/29 18:34:07 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_chunk_vars
{
	int		top_count;
	int		aux;
	int		div_count;
	int		do_rb;
	t_list	*head_a;
}t_chunk_vars;

int		check_doubles(char **argv, int check);
int		check_digits(char **argv, int check);
int		is_sorted(t_list *stack_a, int check);
void	free_arr(char **tmp, int argc);
void	read_inst(t_list *stack_a, t_list *stack_b);
t_list	*map_list(t_list *stack_a);
int		rotate_bot(int i, int count, t_list **aux_b);
int		rotate_top(int i, int count, t_list **aux_b);
t_list	*sort_three(t_list *stack_a);
t_list	*sort_four(t_list *stack_a, t_list *stack_b);
t_list	*sort_five(t_list *stack_a, t_list *stack_b);
t_list	*break_chunks(t_list *stack_a, t_list *stack_b, int chunk_size, int ls);
t_list	*sa(t_list *stack_a, int check);
t_list	*sb(t_list *stack_b, int check);
t_list	*pa(t_list *stack_b, t_list **stack_a, int check);
t_list	*pb(t_list *stack_a, t_list **stack_b, int check);
t_list	*ra(t_list *stack_a, int check);
t_list	*rb(t_list *stack_b, int check);
t_list	*rra(t_list *stack_a, int check);
t_list	*rrb(t_list *stack_b, int check);

#endif
