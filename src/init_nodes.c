/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:18 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/16 09:58:28 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	set_position(t_node *stack)
{
	int	pos;
	int	median;

	if (!stack)
		return ;
	pos = 0;
	median = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->position = pos;
		if (pos < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		pos++;
	}
}

void	set_target_node(t_node *stack_a, t_node *stack_b)
{
	t_node		*origin;
	t_node		*target;
	long		best_match;

	origin = stack_a;
	while (stack_b)
	{
		diff_min = INT32_MAX;
		while (stack_a)
		{
			if (stack_a->data > stack_b->data
				&& stack_a->data < best_match)
			{
				target = stack_a;
				best_match = stack_a->data;
			}
			stack_a = stack_a->next;
		}
		stack_a = origin;
		if (diff_min == INT32_MAX)
			stack_b->target_node = get_smallest(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	set_price(t_node *stack_a, t_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	while (stack_b)
	{
		stack_b->price = stack_b->position;
		if (!stack_b->above_median)
			stack_b->price = size_b - stack_b->position;
		if (stack_b->target_node->above_median)
			stack_b->price += stack_b->target_node->position;
		else
			stack_b->price += size_a - stack_b->target_node->position;
		stack_b = stack_b->next;
	}
}

t_node	*get_cheapest(t_node *stack)
{
	t_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->price < cheapest->price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	init_nodes(t_node **stack_a, t_node **stack_b)
{
	set_position(*stack_a);
	set_position(*stack_b);
	set_target_node(*stack_a, *stack_b);
	set_price(*stack_a, *stack_b);
}
