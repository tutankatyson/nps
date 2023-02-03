/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:00:59 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/14 00:48:51 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

void	*ft_calloccc(size_t elem, size_t size_elem)
{
	char	*ptr;

	ptr = NULL;
	if (!elem || !size_elem || elem * size_elem < 0)
		return (NULL);
	ptr = (char *)malloc(elem * size_elem);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, elem * size_elem);
	return (ptr);
}

/*****************************************************************************
 * 
 * 		                f t _ s t r c h r ( s t r , c h ) 
 *
 *  Devuelve la posición (empezando por 1) del caracter ch en el string.
 * 	Si no encuentra ch devuelve 0
 *
 * ***************************************************************************/

size_t	ft_strchrrr(char *str, char ch)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != 0)
	{
		if (str[cont] == ch)
		{
			return (cont + 1);
		}
		cont++;
	}
	return (0);
}

/********************************************************************
 * 
 * 		f t _ a p p e n d ( b a s e , a p p , a p p _ s i z e ) 
 *
 * Aañade una cadena app hasta la posicion app_size a la cadena base, 
 * realocando la memoria
 *
 * ******************************************************************/

char	*ft_append(char *base, char *app, size_t app_size)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!base)
		return (0);
	if (!app || app_size < 1)
		return (base);
	ptr = ft_calloccc(ft_strlen(base) + app_size + 1, sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		ptr[i] = base[i];
		i++;
	}
	free(base);
	j = 0;
	while (j < app_size)
		ptr[i++] = app[j++];
	ptr[i] = 0;
	return (ptr);
}
