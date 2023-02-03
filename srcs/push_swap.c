/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:26 by marvin            #+#    #+#             */
/*   Updated: 2022/12/09 13:57:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
 * 
 * 		* OK *	Si no hay parametros devuelve el control al usuario
 * 		* OK *  Muestra "Error\n" en la salida de errores estandar
 * 		* OK *		Agumento no es entero
 * 		* OK *		Argumento fuera del rango int
 * 		* OK *		Números duplicados 
 * 
 * 		* OK *		Cambiar printf por ft_printf
 * 		* OK *		Comprobar memory leaks  (liberar memorias)
 * 
 ****************************************************************************/

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1 || ft_find_error(argc, argv))
		return (0);
	ft_init(&a, argc, argv);
	ft_init(&b, argc, NULL);
	if (ft_small_stack(&a))
		ps_best_way(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}

void	ps_best_way(t_stack *a, t_stack *b)
{
	ft_pushn(b, a, a->size - 3);
	ft_ord3(a);
	ft_insert_best(a, b);
	ft_center(a);
}
