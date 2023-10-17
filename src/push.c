/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:10:30 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/17 09:21:40 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*to_push;

	if (!stack_from || !*stack_from)
		return ;
	to_push = *stack_from;
	*stack_from = (*stack_from)->next;
	if (!*stack_to)
	{
		*stack_to = to_push;
		(*stack_to)->next = NULL;
	}
	else
	{
		to_push->next = *stack_to;
		*stack_to = to_push;
	}
}

void	pa(t_node **stack_a, t_node **stack_b, bool silent)
{
	push(stack_b, stack_a);
	if (!silent)
		ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b, bool silent)
{
	push(stack_a, stack_b);
	if (!silent)
		ft_printf("pb\n");
}
