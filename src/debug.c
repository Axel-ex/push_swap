/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:22:19 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/04 09:39:35 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	read_stack(t_node *stack, bool flag_a)
{
	if (flag_a)
		ft_printf("Stack_a:\n");
	else
		ft_printf("Stack_b:\n");
	while (stack)
	{
		ft_printf("%d", stack->data);
		if (stack->next != NULL)
			ft_printf(", ");
		stack = stack->next;
	}
	ft_printf("\n\n");
}
