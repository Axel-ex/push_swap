/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:22:19 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/21 17:17:03 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	read_stack(t_node *stack, bool flag_a)
{
	if (flag_a)
		printf("Stack_a:\n");
	else
		printf("Stack_b:\n");
	while (stack)
	{
		printf("--------------------\n");
		if (stack->position)
			printf("position: %d\n", stack->position);
		printf("data: %d\n", stack->data);
		if (stack->price)
			printf("price: %d\n", stack->price);
		if (stack->target_node)
			printf("pos of target_node: %d\n", stack->target_node->position);
		printf("--------------------\n\n");
		stack = stack->next;
	}
	printf("\n\n");
}
