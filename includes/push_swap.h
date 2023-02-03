/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:13:40 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/14 00:37:11 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libft.h"

/********ESTRUCTURAS*******/

typedef struct mi_stack
{
	int		*stack;
	char	ch;
	int		size;
	int		last;
	int		max;
	int		min;
}					t_stack;

/** * * * * * * A L G O R H I M S * * * * * **/

void	ps_best_way(t_stack *a, t_stack *b);

void	ft_insert_best(t_stack *a, t_stack *b);			
void	ft_inserton(t_stack *from, int fromi, t_stack *to, int toi);
int		ft_findpos(int num, t_stack *st);

/** * * * * B A S I C * T O O L S * * * * **/

/********STACKS********/

void	ft_init(t_stack *stack, int argc, char **argv);
int		check(t_stack *st);

/********STATS********/

int		ft_max(t_stack *st);
int		ft_min(t_stack *st);
int		ft_find_min(t_stack *st);

/** * * * * * A D V A N C E D * T O O L S * * * * * **/

void	ft_pushn(t_stack *to, t_stack *from, int n);
void	ft_ord3(t_stack *st);
void	ft_center(t_stack *st);
int		ft_isorder(t_stack *st);

int		ft_small_stack(t_stack	*a);

/** * * * * * M A T H * T O O L S * * * * * **/

int		abs(int num);
int		ft_mayor(int a, int b);
int		ft_menor(int a, int b);
int		ft_menor3(int a, int b, int c);

/** * * * * * E R R O R * T O O L S * * * * * **/

int		ft_find_error(int argc, char **argv);
int		ft_input_error(const char *str);

/** * * * * * * O P E R A T I O N S * * * * * **/

void	swap(t_stack *st);
void	rotate(t_stack *st);
void	reverse(t_stack *st);
void	ss(t_stack *sta, t_stack *stb);
void	rr(t_stack *sta, t_stack *stb);
void	rrr(t_stack *sta, t_stack *stb);
int		push(t_stack *to, t_stack *from);

#endif
