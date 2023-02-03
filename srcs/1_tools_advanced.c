/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_tools_advanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:36:22 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/12 18:01:35 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pushn(t_stack *to, t_stack *from, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		push(to, from);
		i++;
	}
}

int	ft_isorder(t_stack *st)
{
	int	i;
	int	step;

	i = 0;
	step = 0;
	if (st->stack[st->last] > st->stack[0] && step == 0)
		step++;
	while (i < st->last)
	{
		if (st->stack[i] > st->stack[i + 1] && step == 0)
			step++;
		else
			if (st->stack[i] > st->stack[i + 1] && step != 0)
				return (0);
		i++;
	}
	return (1);
}

void	ft_ord3(t_stack *st)
{
	if (st->stack[0] < st->stack[1]
		&& st->stack[1] > st->stack[2]
		&& st->stack[2] > st->stack[0])
		rotate(st);
	if (st->stack[0] > st->stack[1]
		&& st->stack[1] > st->stack[2]
		&& st->stack[2] < st->stack[0])
		swap(st);
	if (st->stack[0] > st->stack[1]
		&& st->stack[1] < st->stack[2]
		&& st->stack[2] > st->stack[0])
		swap(st);
	else if (st->stack[0] < st->stack[1]
		&& st->stack[1] > st->stack[2]
		&& st->stack[2] < st->stack[0])
		reverse(st);
	else if (st->stack[0] > st->stack[1]
		&& st->stack[1] < st->stack[2]
		&& st->stack[2] < st->stack[0])
		rotate(st);
}

void	ft_center(t_stack *st)
{
	int	min;

	min = ft_min(st);
	if (ft_find_min(st) < st->size / 2)
		while (st->stack[0] != min)
			rotate(st);
	else
		while (st->stack[0] != min)
			reverse(st);
}

/*********************************************************************
 * 
 * 		Gestoina los siguientes casos especiales
 * 			* Stack Odenado y centrado
 * 			* Stack Odenado	(solo hay que centrarlo)
 * 			* Stack de 2 elementos
 * 
 **********************************************************************/

int	ft_small_stack(t_stack	*st)
{
	if (check(st))
		return (0);
	if (st->size == 2)
	{
		swap(st);
		return (0);
	}
	if (ft_isorder(st))
	{
		ft_center(st);
		return (0);
	}
	return (1);
}
