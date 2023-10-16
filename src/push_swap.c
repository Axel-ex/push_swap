/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:55:57 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/11 09:43:48 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	finish_rotation(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, false);
			else
				ra(stack, true);
		}
		else
		{
			if (top->above_median)
				rb(stack, false);
			else
				rb(stack, true);
		}
	}
}

static void	move_node(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*stack_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest, false);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest, true);
	finish_rotation(stack_b, cheapest, 'b');
	finish_rotation(stack_a, cheapest->target_node, 'a');
	pa(stack_a, stack_b);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest;

	if (get_stack_size(*stack_a) == 5)
		small_sort(stack_a, stack_b);
	else
	{
		while (get_stack_size(*stack_a) > 3)
			pb(stack_a, stack_b);
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		init_nodes(stack_a, stack_b);
		move_node(stack_a, stack_b);
	}
	set_position(*stack_a);
	smallest = get_smallest(*stack_a);
	while (*stack_a != smallest)
	{
		if (smallest->above_median)
			ra(stack_a, false);
		else
			ra(stack_a, true);
	}
}
