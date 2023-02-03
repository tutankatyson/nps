/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_tools_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:11:33 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/12 18:01:37 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** * * * * * * S T A C K S * * * * * * **/

void	ft_init(t_stack *stack, int argc, char **argv)
{
	int	i;

	stack->size = argc - 1;
	stack->stack = (int *)ft_calloc(sizeof(int), (argc - 1));
	if (argv == NULL)
	{
		stack->last = -1;
		stack->ch = 'b';
	}
	else
	{
		stack->last = argc - 2;
		stack->ch = 'a';
		i = 1;
		while (i < argc)
		{
			stack->stack[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		stack->max = ft_max(stack);
		stack->min = ft_min(stack);
	}
}

int	check(t_stack *st)
{
	int	i;

	i = 1;
	while (i < st->size)
	{
		if (!(st->stack[i - 1] < st->stack[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/** * * * * * * S T A T S * * * * * * **/

int	ft_max(t_stack *st)
{
	int	i;
	int	temp;

	i = 1;
	temp = st->stack[0];
	while (i <= st->last)
	{
		if (temp < st->stack[i])
			temp = st->stack[i];
		i++;
	}
	return (temp);
}

int	ft_min(t_stack *st)
{
	int	i;
	int	temp;

	i = 1;
	temp = st->stack[0];
	while (i <= st->last)
	{
		if (temp > st->stack[i])
			temp = st->stack[i];
		i++;
	}
	return (temp);
}

int	ft_find_min(t_stack *st)
{
	int	i;
	int	temp;
	int	min;

	i = 1;
	temp = st->stack[0];
	min = 0;
	while (i <= st->last)
	{
		if (temp > st->stack[i])
		{
			temp = st->stack[i];
			min = i;
		}
		i++;
	}
	return (min);
}
