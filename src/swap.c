/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:07:38 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/11 17:23:49 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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
		if ((*stack)->next->next)
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
