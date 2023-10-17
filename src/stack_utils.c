/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:44:18 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/17 09:00:29 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	node_add_back(long nb, t_node **stack)
{
	t_node	*new;
	t_node	*last;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = (int)nb;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		last = get_last_node(*stack, false);
		last->next = new;
	}
}

t_node	*get_last_node(t_node *stack, bool second_last)
{
	if (!stack)
		return (NULL);
	if (!second_last)
		while (stack->next)
			stack = stack->next;
	else
		while (stack->next->next)
			stack = stack->next;
	return (stack);
}

int	get_stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_node	*get_highest(t_node *stack)
{
	t_node	*highest;

	if (!stack)
		return (NULL);
	highest = stack;
	while (stack)
	{
		if (stack->data > highest->data)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_node	*get_smallest(t_node *stack)
{
	t_node	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->data < smallest->data)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}
