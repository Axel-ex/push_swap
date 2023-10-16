/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:18 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/10 16:28:39 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	get_position(t_node *stack)
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

void	get_target_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*origin;
	t_node	*target;
	int		diff_min;

	origin = stack_a;
	while (stack_b)
	{
		diff_min = __INT_MAX__;
		while (stack_a)
		{
			if (stack_a->data > stack_b->data
				&& (stack_a->data - stack_b->data) < diff_min)
			{
				target = stack_a;
				diff_min = stack_a->data - stack_b->data;
			}
			stack_a = stack_a->next;
		}
		stack_a = origin;
		if (diff_min == __INT_MAX__)
			stack_b->target_node = get_smallest(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	get_price(t_node *stack_a, t_node *stack_b)
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
	get_position(*stack_a);
	get_position(*stack_b);
	get_target_node(*stack_a, *stack_b);
	get_price(*stack_a, *stack_b);
}
