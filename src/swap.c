/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:07:38 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/02 16:04:51 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* swap the two first node located on top of the stack*/

static void	swap(t_node **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->next)
	{
		(*stack)->next->prev = NULL;
		(*stack)->prev = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev->next = *stack;
		*stack = (*stack)->prev;
		(*stack)->next->next->prev = (*stack)->next;
	}
}

void	sa(t_node **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_node **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
