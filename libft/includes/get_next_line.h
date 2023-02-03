/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:01:28 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/14 00:50:16 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define CH '\n'
# define BUFFER_SIZE 20

char	*get_next_line(int fd);
char	*ft_append(char *base, char *app, size_t app_size);
void	*ft_calloccc(size_t elem, size_t size_elem);
size_t	ft_strchrrr(char *str, char ch);

#endif