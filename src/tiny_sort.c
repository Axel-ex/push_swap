/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:34:49 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/03 11:09:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	tiny_sort(t_node **stack)
{
	t_node	*highest;

	highest = get_highest(*stack);
	if (highest == *stack)
		ra(stack, false);
	else if (highest == (*stack)->next)
		ra(stack, true);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	small_sort(t_node **stack_a, t_node **stack_b)
{
	while (get_stack_size(*stack_a) > 3)
	{
		init_nodes(stack_a, stack_b);
		finish_rotation(stack_a, get_smallest(*stack_a), 'a');
		pb(stack_a, stack_b);
	}
}
