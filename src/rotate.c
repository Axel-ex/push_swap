/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:31:57 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/17 09:25:48 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	rotate(t_node **stack, bool reverse_flag)
{
	t_node	*to_rotate;
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || get_stack_size(*stack) == 1)
		return ;
	to_rotate = *stack;
	last = get_last_node(*stack, false);
	second_last = get_last_node(*stack, true);
	if (!reverse_flag)
	{
		*stack = (*stack)->next;
		last->next = to_rotate;
		to_rotate->next = NULL;
	}
	else
	{
		last->next = *stack;
		*stack = last;
		second_last->next = NULL;
	}
}

void	ra(t_node **stack_a, bool reverse_flag, bool silent)
{
	rotate(stack_a, reverse_flag);
	if (!silent)
	{
		if (reverse_flag)
			ft_printf("rra\n");
		else
			ft_printf("ra\n");
	}
}

void	rb(t_node **stack_b, bool reverse_flag, bool silent)
{
	rotate(stack_b, reverse_flag);
	if (!silent)
	{
		if (reverse_flag)
			ft_printf("rrb\n");
		else
			ft_printf("rb\n");
	}
}

void	rotate_two(t_node **stack_a, t_node **stack_b,
	bool reverse_flag, bool silent)
{
	if (!reverse_flag)
	{
		rotate(stack_a, false);
		rotate(stack_b, false);
		if (!silent)
			ft_printf("rr\n");
	}
	else
	{
		rotate(stack_a, true);
		rotate(stack_b, true);
		if (!silent)
			ft_printf("rrr\n");
	}
}

void	rotate_both(t_node **stack_a, t_node **stack_b, bool reverse_flag)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*stack_b);
	while (cheapest != *stack_b && cheapest->target_node != *stack_a)
		rotate_two(stack_a, stack_b, reverse_flag, false);
}
