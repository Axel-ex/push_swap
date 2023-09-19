/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:22:19 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/18 16:21:31 by achabrer         ###   ########.fr       */
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
		printf("%d", stack->data);
		if (stack->next)
			printf(", ");
		stack = stack->next;
	}
	printf("\n\n");
}
