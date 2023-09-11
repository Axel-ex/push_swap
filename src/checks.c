/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:41:07 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/11 15:50:10 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

long	*argv_to_int(char **argv, int argc)
{
	long	*argv_int;
	long	*origin;

	argv_int = (long *)malloc(sizeof(long) * argc - 1);
	if (!argv_int)
		return (NULL);
	origin = argv_int;
	argv++;
	while (*argv)
		*argv_int++ = ft_atol(*argv++);
	return (origin);
}

static bool	check_valid_char(char **argv)
{
	char	*s;

	argv++;
	while (*argv)
	{
		s = *argv;
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


static bool	check_duplicates(long *argv_int, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (argv_int[i])
	{
		j = 1;
		while (j < argc - 1)
		{
			if (argv_int[i] == argv_int[j] && i != j)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_outbounds(long *argv_int)
{
	while (*argv_int)
	{
		if (*argv_int < INT32_MIN || *argv_int > INT32_MAX)
			return (false);
		argv_int++;
	}
	return (true);
}

bool	check_valid(char **argv, int argc)
{
	long	*argv_int;

	if (check_valid_char(argv))
	{
		argv_int = argv_to_int(argv, argc);
		if (check_outbounds(argv_int) && check_duplicates(argv_int, argc))
		{
			free(argv_int);
			return (true);
		}
		free(argv_int);
	}
	return (false);
}
