/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_insert_best.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:43:56 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/13 19:24:17 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_calculator(t_stack *from, int fromi, t_stack *to, int toi);

void	ft_insert_best(t_stack *from, t_stack *to)
{
	int	candidato;
	int	calc;
	int	i;

	while (to->last >= 0)
	{
		candidato = 0;
		calc = ft_calculator(to, 0, from, ft_findpos(to->stack[0], from));
		i = 0;
		while (i <= to->last)
		{
			if (ft_calculator(to, i, from,
					ft_findpos(to->stack[i], from)) < calc)
			{
				candidato = i;
				calc = ft_calculator(to, i, from,
						ft_findpos(to->stack[i], from));
			}
			i++;
		}
		ft_inserton(to, candidato, from,
			ft_findpos(to->stack[candidato], from));
	}
}

static int	ft_calculator(t_stack *from, int fromi, t_stack *to, int toi)
{
	int	rra;
	int	rrb;
	int	cr;
	int	crr;
	int	simple;

	rra = from->last + 1 - fromi;
	rrb = to->last + 1 - toi;
	cr = ft_mayor(fromi, toi);
	crr = ft_mayor(rra, rrb);
	simple = ft_menor(fromi, rra) + ft_menor(toi, rrb);
	return (ft_menor3(cr, crr, simple) + 1);
}

void	ft_insert_n_best(t_stack *a, t_stack *b, int n)
{
	int	candidato;
	int	calc;
	int	i;

	while (b->last >= 0 && n > 0)
	{
		candidato = 0;
		calc = ft_calculator(b, 0, a, ft_findpos(b->stack[0], a));
		i = 0;
		while (i <= b->last)
		{
			if (ft_calculator(b, i, a, ft_findpos(b->stack[i], a)) < calc)
			{
				candidato = i;
				calc = ft_calculator(b, i, a, ft_findpos(b->stack[i], a));
			}
			i++;
		}
		ft_inserton(b, candidato, a, ft_findpos(b->stack[candidato], a));
		n--;
	}
}
