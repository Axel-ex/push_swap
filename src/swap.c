/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:07:38 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/17 09:25:28 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	swap(t_node **stack)
{
	t_node	*buf;

	if (!stack || !*stack)
		return ;
	if ((*stack)->next)
	{
		buf = *stack;
		*stack = (*stack)->next;
		buf->next = (*stack)->next;
		(*stack)->next = buf;
	}
}

void	sa(t_node **stack, bool silent)
{
	swap(stack);
	if (!silent)
		ft_printf("sa\n");
}

void	sb(t_node **stack, bool silent)
{
	swap(stack);
	if (!silent)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b, bool silent)
{
	swap(stack_a);
	swap(stack_b);
	if (!silent)
		ft_printf("ss\n");
}
