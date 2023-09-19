/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:41:07 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/13 09:47:21 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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

bool	check_duplicates(long nb, t_node *stack)
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
