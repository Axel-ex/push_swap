/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:44:18 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/11 15:15:17 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

long	ft_atol(const char *s)
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

bool	is_sorted(char **argv, int argc)
{
	int		i;
	long	*argv_int;

	i = 1;
	argv_int = argv_to_int(argv, argc);
	while (i < argc - 1)
	{
		if (argv_int[i] < argv_int[i - 1])
			return (false);
		i++;
	}
	free (argv_int);
	return (true);
}
