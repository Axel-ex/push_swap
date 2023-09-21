/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:34:49 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/21 11:06:05 by achabrer         ###   ########.fr       */
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
