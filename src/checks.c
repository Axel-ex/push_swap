/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:41:07 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/11 11:09:07 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

bool	check_valid_char(char **argv)
{
	char	*s;

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
