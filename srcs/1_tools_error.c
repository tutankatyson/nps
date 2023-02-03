/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_tools_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:21:03 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/13 18:44:31 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_input_error(const char *str)
{
	int	temp;
	int	n;
	int	sign;

	sign = 0;
	n = 0;
	temp = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = (n * 10) - (*str - '0');
		if (temp < n || (!sign && n == -2147483648))
			return (1);
		temp = n;
		str++;
	}
	if (*str != '\0')
		return (1);
	return (0);
}

int	ft_find_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (ft_input_error(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
