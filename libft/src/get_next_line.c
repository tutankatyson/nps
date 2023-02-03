/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:54:59 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/14 00:49:25 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/**************************************************************************
 * 
 * 					 v o i d     c u t _ b u f f e r ( * b u f f ,  i )
 * 
 * 	Recorta y cuerra el string buff en la posicion i
 *  
 ***************************************************************************/

static void	ft_cutbuffer(char *buff, size_t i)
{
	size_t	cont;

	cont = 0;
	while (cont + i < BUFFER_SIZE)
	{
		buff[cont] = buff[cont + i];
		cont++;
	}
	buff[cont] = 0;
}

/*************************************************************************
 * 
 * 					 v o i d     f i l l _ b u f f e r
 * 
**************************************************************************/

static ssize_t	fill_buffer(char *buff, int fd)
{
	ssize_t	reads;

	reads = 0;
	if (!buff)
		return (0);
	while (reads < BUFFER_SIZE)
	{
		buff[reads] = 0;
		reads ++;
	}
	reads = read(fd, buff, BUFFER_SIZE);
	buff[reads] = 0;
	return (reads);
}

/**************************************************************************
 * 
 * 					 * g e t _ l i n e
 *  
 **************************************************************************/

static char	*get_line(char *buff, char stp, int fd)
{
	char	*txt;
	size_t	i;

	txt = NULL;
	txt = (char *)ft_calloccc(1, sizeof(char));
	if (!txt)
		return (NULL);
	while (!ft_strchrrr(buff, stp))
	{
		txt = ft_append(txt, buff, BUFFER_SIZE);
		if (!fill_buffer(buff, fd))
			return (txt);
	}
	i = ft_strchrrr(buff, stp);
	txt = ft_append(txt, buff, i);
	ft_cutbuffer(buff, i);
	return (txt);
}

/**************************************************************************
 * 
 * 			  g e t _ n e x t _ l i n e
 *  
 ****************************************************************************/

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*txt;

	if (!buff)
		buff = (char *)ft_calloccc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff || read(fd, buff, 0) == -1 || BUFFER_SIZE < 1)
	{
		free(buff);
		buff = 0;
		return (0);
	}
	if (*buff != '\0')
		txt = get_line(buff, CH, fd);
	else
	{
		if (fill_buffer(buff, fd) != 0)
			txt = get_line(buff, CH, fd);
		else
		{
			free(buff);
			buff = 0;
			txt = 0;
		}
	}
	return (txt);
}
