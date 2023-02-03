/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_checker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:10:35 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/14 01:27:18 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

void	m_swap(t_stack *st);
void	m_rotate(t_stack *st);
void	m_reverse(t_stack *st);
int		m_push(t_stack *to, t_stack *from);
void	m_ss(t_stack *sta, t_stack *stb);
void	m_rr(t_stack *sta, t_stack *stb);
void	m_rrr(t_stack *sta, t_stack *stb);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*operation;

	if (argc == 1 || ft_find_error(argc, argv))
		return (0);
	ft_init(&a, argc, argv);
	ft_init(&b, argc, NULL);
	operation = get_next_line(0);
	while (operation != 0)
	{
		if (!ft_strncmp(operation, "sa", ft_strlen(operation)))
			m_swap(&a);
		else if (!ft_strncmp(operation, "sb", ft_strlen(operation)))
			m_swap(&b);
		else if (!ft_strncmp(operation, "ss", ft_strlen(operation)))
			m_ss(&a, &b);
		else if (!ft_strncmp(operation, "ra", ft_strlen(operation)))
			m_rotate(&a);
		else if (!ft_strncmp(operation, "rb", ft_strlen(operation)))
			m_rotate(&b);
		else if (!ft_strncmp(operation, "rr", ft_strlen(operation)))
			m_rr(&a, &b);
		else if (!ft_strncmp(operation, "rra", ft_strlen(operation)))
			m_reverse(&a);
		else if (!ft_strncmp(operation, "rrb", ft_strlen(operation)))
			m_reverse(&b);
		else if (!ft_strncmp(operation, "rrr", ft_strlen(operation)))
			m_rrr(&a, &b);
		else if (!ft_strncmp(operation, "pa", ft_strlen(operation)))
			m_push(&a, &b);
		else if (!ft_strncmp(operation, "pb", ft_strlen(operation)))
			m_push(&b, &a);
		else
			printf("Error\n");
		free(operation);
		operation = get_next_line(0);
	}
	if (check(&a))
		printf("KO\n");
	else
		printf("OK\n");
	free(a.stack);
	free(b.stack);
	return (0);
}

void	m_swap(t_stack *st)
{
	int	temp;

	if (st->last > 1)
	{
	temp = st->stack[0];
	st->stack[0] = st->stack[1];
	st->stack[1] = temp;
	}
}

/*rotate*/

void	m_rotate(t_stack *st)
{
	int	i;
	int	temp;

	i = 1;
	if (st->last > 0)
	{
		temp = st->stack[0];
		while (i <= st->last)
		{
			st->stack[i - 1] = st->stack[i];
			i++;
		}
		st->stack[i - 1] = temp;
	}
}

/*reverse*/

void	m_reverse(t_stack *st)
{
	int	i;
	int	temp;

	i = 0;
	temp = st->stack[st->last];
	while (i < st->last)
	{
		st->stack[st->last - i] = st->stack[st->last - i - 1];
		i++;
	}
	st->stack[0] = temp;
}

/*push*/

int	m_push(t_stack *to, t_stack *from)
{
	int	i;

	if (from->last == -1)
		return (0);
	i = 0;
	while (i <= to->last)
	{
		to->stack[to->last - i + 1] = to->stack[to->last - i];
		i++;
	}
	to->stack[0] = from->stack[0];
	to->last++;
	i = 0;
	while (i < from->last)
	{
		from->stack[i] = from->stack[i + 1];
		i++;
	}
	from->last--;
	return (1);
}

void	m_ss(t_stack *sta, t_stack *stb)
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
}

/*rotate*/

void	m_rr(t_stack *sta, t_stack *stb)
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
}

/*reverse*/

void	m_rrr(t_stack *sta, t_stack *stb)
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
}
