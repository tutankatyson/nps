/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:46:38 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/11 22:42:10 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	char	*ptr;

	ptr = s;
	while (len > 0)
	{
		*ptr = 0;
		ptr++;
		len--;
	}
}