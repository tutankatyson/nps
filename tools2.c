/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:36:22 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/10 17:35:20 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushn(my_stack *to, my_stack *from, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		push(to, from);
		i++;
	}
}

void	ft_ord3(my_stack *st)
{
	if (st->stack[0] < st->stack[1] && st->stack[1] > st->stack[2]
		&& st->stack[2] > st->stack[0])
		rotate(st);
	if (st->stack[0] > st->stack[1] && st->stack[1] > st->stack[2]
		&& st->stack[2] < st->stack[0])
		swap(st);
	if (st->stack[0] > st->stack[1] && st->stack[1] < st->stack[2]
		&& st->stack[2] > st->stack[0])
		swap(st);
	else if (st->stack[0] < st->stack[1] && st->stack[1] > st->stack[2]
		&& st->stack[2] < st->stack[0])
		reverse(st);
	else if (st->stack[0] > st->stack[1] && st->stack[1] < st->stack[2]
		&& st->stack[2] < st->stack[0])
		rotate(st);
}

void	ft_center(my_stack *st)
{
	int	min;

	min = ft_min(st);
	if (ft_find_min(st) < st->size / 2)
	{
		while (st->stack[0] != min)
			rotate(st);
	}
	else
	{
		while (st->stack[0] != min)
			reverse(st);
	}
}
