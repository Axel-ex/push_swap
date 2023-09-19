/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:56:33 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/19 10:49:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	stack_init(t_node **stack, char **argv, bool split_flag)
{
	long	nb;
	int		i;

	i = 1;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (nb < INT32_MIN || nb > INT32_MAX)
			exit_error(stack, argv, split_flag);
		if (!check_duplicates(nb, *stack))
			exit_error(stack, argv, split_flag);
		node_add_back(nb, stack);
		i++;
	}
	if (split_flag)
		free_matrix(argv);
}

void	node_add_back(long nb, t_node **stack)
{
	t_node	*new;
	t_node	*last;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = (int)nb;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = get_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}
