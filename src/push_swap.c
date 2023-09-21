/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:55:57 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/21 16:50:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	read_stack(*stack_a, true);
	while (stack_size-- > 3)
		pb(stack_a, stack_b);
	init_nodes(stack_a, stack_b);
	read_stack(*stack_a, true);
	read_stack(*stack_b, false);
}
