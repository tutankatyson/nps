/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserton.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:36:27 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/10 16:35:05 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** * * * * * * *f t _ i n s e r t o n * * * * * * * **
 * 	
 *	Insert a number from stack "from" to stack "to"
 * 	in the positions defined for "fromi" and "toi"
 * 
 * 	This algorhym do the insertion by the faster way
 *	attemping to use double rotate and double reverse
 * 
 * 	ft_rr: insert using rotate & double rotate
 * 	ft_rrr: insert using reverse & double reverse
 * 	ft_simple: insert using reverse and rotate 
 * 
 * 	cr:     Nº operations using rotate and rr.
 * 	crr:    Nº operations using reverse & rrr.
 * 	simple: Nº operations using rotate & reverse.
 * 
 ** * * * * * * * * * * * * * * * * * * * * * * * * **/

#include "push_swap.h"

static void	ft_rr(my_stack *from, int fromi, my_stack *to, int toi);
static void	ft_rrr(my_stack *from, int fromi, my_stack *to, int toi);
static void	ft_simple(my_stack *from, int fromi, my_stack *to, int toi);

void	ft_inserton(my_stack *from, int fromi, my_stack *to, int toi)
{
	int	cr;
	int	crr;
	int	besta;
	int	bestb;
	int	simple;

	if (fromi == 0 && toi == 0)
		push(to, from);
	else
	{
	cr = ft_mayor(fromi, toi);
	crr = ft_mayor((from->last + 1 - fromi), (to->last + 1 - toi));
	besta = ft_menor(fromi, (from->last + 1 - fromi));
	bestb = ft_menor(toi, (to->last + 1 - toi));
	simple = besta + bestb;
		if (cr <= crr && cr <= simple)
			ft_rr(from, fromi, to, toi);
		else if (crr <= cr && crr <= simple)
			ft_rrr(from, fromi, to, toi);
		else if (simple <= cr && simple <= crr)
			ft_simple(from, fromi, to, toi);
		push(to, from);
	}
}

static void	ft_rr(my_stack *from, int fromi, my_stack *to, int toi)
{
	int	i;

	if (fromi < toi)
	{
		i = 0;
		while (i++ < fromi)
			rr(from, to);
		i = 0;
		while (i++ < toi - fromi)
			rotate(to);
	}
	else
	{
		i = 0;
		while (i++ < toi)
			rr(from, to);
		i = 0;
		while (i++ < fromi - toi)
			rotate(from);
	}
}

static void	ft_rrr(my_stack *from, int fromi, my_stack *to, int toi)
{
	int	i;

	if (from->last - fromi <= to->last - toi)
	{
		i = 0;
		while (i++ < 1 + from->last - fromi)
			rrr(from, to);
		i = 0;
		while (i++ < (to->last - toi) - (from->last - fromi))
			reverse(to);
	}
	else
	{
		i = 0;
		while (i++ < 1 + to->last - toi)
			rrr(from, to);
		i = 0;
		while (i++ < (from->last - fromi) - (to->last - toi))
			reverse(from);
	}
}

static void	ft_simple(my_stack *from, int fromi, my_stack *to, int toi)
{
	int	i;

	i = 0;
	if (fromi < (from->last + 1 - fromi))
		while (i++ < fromi)
			rotate(from);
	else
		while (i++ < 1 + from->last - fromi)
			reverse(from);
	i = 0;
	if (toi < (to->last + 1 - toi))
		while (i++ < toi)
			rotate(to);
	else
		while (i++ < 1 + to->last - toi)
			reverse(to);
}
