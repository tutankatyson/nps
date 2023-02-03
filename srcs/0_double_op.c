/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_double_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:25 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/12 18:01:31 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *sta, t_stack *stb)
{
	int	temp;

	if (sta->last > 1)
	{
	temp = sta->stack[0];
	sta->stack[0] = sta->stack[1];
	sta->stack[1] = temp;
	}
	if (stb->last > 1)
	{
	temp = stb->stack[0];
	stb->stack[0] = stb->stack[1];
	stb->stack[1] = temp;
	}
	ft_putchar_fd('s', 1);
	ft_putchar_fd('s', 1);
	ft_putchar_fd('\n', 1);
}

/*rotate*/

void	rr(t_stack *sta, t_stack *stb)
{
	int	i;
	int	temp;

	i = 1;
	temp = sta->stack[0];
	while (i <= sta->last)
	{
		sta->stack[i - 1] = sta->stack[i];
		i++;
	}
	sta->stack[i - 1] = temp;
	i = 1;
	temp = stb->stack[0];
	while (i <= stb->last)
	{
		stb->stack[i - 1] = stb->stack[i];
		i++;
	}
	stb->stack[i - 1] = temp;
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('\n', 1);
}

/*reverse*/

void	rrr(t_stack *sta, t_stack *stb)
{
	int	i;
	int	temp;

	i = 0;
	temp = sta->stack[sta->last];
	while (i < sta->last)
	{
		sta->stack[sta->last - i] = sta->stack[sta->last - i - 1];
		i++;
	}
	sta->stack[0] = temp;
	i = 0;
	temp = stb->stack[stb->last];
	while (i < stb->last)
	{
		stb->stack[stb->last - i] = stb->stack[stb->last - i - 1];
		i++;
	}
	stb->stack[0] = temp;
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('\n', 1);
}
