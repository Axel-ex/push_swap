/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:55:57 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/02 16:56:46 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	finish_rotation(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (*stack_b != cheapest)
	{
		if (cheapest->above_median)
			rb(stack_b, false);
		else
			rb(stack_b, true);
	}
	while (*stack_a != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			ra(stack_a, false);
		else
			ra(stack_a, true);
	}
}

void	move_node(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*stack_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest, false);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest, true);
	finish_rotation(stack_a, stack_b, cheapest);
	pa(stack_a, stack_b);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest;
	int		stack_size;

	stack_size = get_stack_size(*stack_a);
	while (stack_size-- > 3)
		pb(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		init_nodes(stack_a, stack_b);
		move_node(stack_a, stack_b);
	}
	smallest = get_smallest(*stack_a);
	while (*stack_a != smallest)
	{
		if (smallest->above_median)
			ra(stack_a, false);
		else
			ra(stack_a, true);
	}
}
