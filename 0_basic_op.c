/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_basic_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:08:33 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/11 22:37:27 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *st)
{
	int	temp;

	if (st->last > 1)
	{
	temp = st->stack[0];
	st->stack[0] = st->stack[1];
	st->stack[1] = temp;
	}
	ft_putchar_fd('s', 1);
	ft_putchar_fd(st->ch, 1);
	ft_putchar_fd('\n', 1);
}

/*rotate*/

void	rotate(t_stack *st)
{
	int	i;
	int	temp;

	i = 1;
	if (st->last > 0)
	{
		temp = st->stack[0];
		while (i <= st->last)
		{
			st->stack[i - 1] = st->stack[i];
			i++;
		}
		st->stack[i - 1] = temp;
	}
	ft_putchar_fd('r', 1);
	ft_putchar_fd(st->ch, 1);
	ft_putchar_fd('\n', 1);
}

/*reverse*/

void	reverse(t_stack *st)
{
	int	i;
	int	temp;

	i = 0;
	temp = st->stack[st->last];
	while (i < st->last)
	{
		st->stack[st->last - i] = st->stack[st->last - i - 1];
		i++;
	}
	st->stack[0] = temp;
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(st->ch, 1);
	ft_putchar_fd('\n', 1);
}

/*push*/

static void	ft_new_stats(t_stack *to, t_stack *from)
{
	to->max = ft_max(to);
	to->min = ft_min(to);
	from->min = ft_min(from);
	from->max = ft_max(from);
}

int	push(t_stack *to, t_stack *from)
{
	int	i;

	if (from->last == -1)
		return (0);
	i = 0;
	while (i <= to->last)
	{
		to->stack[to->last - i + 1] = to->stack[to->last - i];
		i++;
	}
	to->stack[0] = from->stack[0];
	to->last++;
	i = 0;
	while (i < from->last)
	{
		from->stack[i] = from->stack[i + 1];
		i++;
	}
	from->last--;
	ft_new_stats(to, from);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(to->ch, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}
