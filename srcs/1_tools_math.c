/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_tools_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:34:58 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/13 18:14:31 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** * * * * * * M A T H * * * * * * **/

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_menor(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_mayor(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_menor3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}
