/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:56:33 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/10 16:29:24 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static long	ft_atol(const char *s)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (ft_isdigit(*s) == 1)
	{
		nb *= 10;
		nb += *s - '0';
		s++;
	}
	return (nb * sign);
}

bool	check_valid_char(char **argv)
{
	char	*s;

	argv++;
	while (*argv)
	{
		s = *argv;
		if (!((*s >= '0' && *s <= '9') || *s == '-' || *s == '+'))
			return (false);
		s++;
		while (*s)
		{
			if (*s < '0' || *s > '9')
				return (false);
			s++;
		}
		argv++;
	}
	return (true);
}

static bool	check_duplicates(long nb, t_node *stack)
{
	if (!stack)
		return (true);
	while (stack)
	{
		if (stack->data == nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	stack_init(t_node **stack, char **argv, bool split_flag)
{
	long	nb;
	int		i;

	i = 1;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (nb < __INT_MAX__ || nb > __INT_MAX__)
			exit_error(stack, argv, split_flag);
		if (!check_duplicates(nb, *stack))
			exit_error(stack, argv, split_flag);
		node_add_back(nb, stack);
		i++;
	}
	if (split_flag)
		free_matrix(argv);
}
