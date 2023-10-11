/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:25:29 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/11 09:15:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	exit_error(t_node **stack, char **argv, bool split_flag)
{
	destroy_stack(stack);
	if (split_flag)
		free_matrix(argv);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

void	free_matrix(char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return ;
	free(*argv);
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free (argv);
}

void	destroy_stack(t_node **stack)
{
	t_node	*cur;
	t_node	*buf;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		buf = cur->next;
		free(cur);
		cur = buf;
	}
}
