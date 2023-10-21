/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:24:16 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/21 13:12:06 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_node	*got_to_node(t_node *stack_a, int index)
{
	while (stack_a && index--)
		stack_a = stack_a->next;
	return (stack_a);
}

int	get_first_occur(t_node *stack_a, int middle_point)
{
	int	first;

	first = 0;
	while (stack_a)
	{
		if (stack_a->data < middle_point)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (0);
}

int	get_last_occur(t_node *stack_a, int middle_point)
{
	t_node	*tmp;
	int		last;

	tmp = get_last_node(stack_a, false);
	last = get_stack_size(stack_a);
	while (tmp->data != stack_a->data)
	{
		if (tmp->data < middle_point)
			return (last);
		last--;
		tmp = got_to_node(stack_a, last);
	}
	return (0);
}
