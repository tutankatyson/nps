/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findposition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:03:44 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/10 18:02:27 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** * * * * * * * f t _ f i n d p o s i t i o n * * * * * * * * * **
 * 
 * 	This function find the position of a number "num" 
 * 	on ordered stack "st" to keep it in order
 * 
 * 	ft_find_extreme_posistion:	Aux function to do the 
 * 								maximun and minimun chases
 * 
 * 
 * 
 ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "push_swap.h"

static int	ft_find_extreme_posistion(int num, my_stack *st);

int	ft_findpos(int num, my_stack *st)
{
	int	position;
	int	i;

//	printf("\nnum:%i ; st:%c\n",num,st->ch);
//	status(st);
	position = 0;
	if (num < st->min || num > st->max)
		return (ft_find_extreme_posistion(num, st));
	if (num < st->stack[0] && num > st->stack[st->last])
		return (position);
	i = 0;
	while (i < st->last)
	{
		position++;
		if (num > st->stack[i] && num < st->stack[i + 1])
			return (position);
		i++;
	}
	printf("\nERROR (find_position)\n");
	return (-1);
}

static int	ft_find_extreme_posistion(int num, my_stack *st)
{
	int	position;

	position = 0;
	if (num < st->min)
	{
		while (position <= st->last)
		{
			if (st->stack[position] == st->min)
				return (position);
			position++;
		}
	}
	else
	{
		while (position <= st->last)
		{
			position++;
			if (st->stack[position - 1] == st->max)
				return (position);
		}
	}
	return (-1);
}
