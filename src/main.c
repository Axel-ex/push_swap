/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:32:17 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/11 15:43:10 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	// t_node	*stack_a;
	// t_node	*stack_b;

	// stack_a = NULL;
	// stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit_error();
	if (argc == 2)
	{
		argc = count_words(argv[1], ' ') + 1;
		argv = split(argv[1], ' ');
	}
	if (!check_valid(argv, argc))
		exit_error();
	// if (!is_sorted(argv, argc))
	// {
	// 	/* algo */
	// }
	destroy_argv(argv, argc);
		//stack_init(stack_a);
	//if not sorted, perform the algo
	return (EXIT_SUCCESS);
}
