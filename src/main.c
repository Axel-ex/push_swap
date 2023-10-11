/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:32:17 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/11 12:07:47 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_SUCCESS);
	if (argc == 2)
		argv = split(argv[1], ' ');
	if (!check_valid_char(argv))
		exit_error(NULL, argv, argc == 2);
	stack_init(&stack_a, argv, argc == 2);
	if (!is_sorted(stack_a))
	{
		if (get_stack_size(stack_a) == 2)
			sa(&stack_a);
		if (get_stack_size(stack_a) == 3)
			tiny_sort(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	return (EXIT_SUCCESS);
}
