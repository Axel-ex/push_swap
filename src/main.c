/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:32:17 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/11 11:04:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	// t_node	*stack_a;
	// t_node	*stack_b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit_error("Please enter arguments.");
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (check_valid_char(argv))
		ft_printf("valid argument");
		//stack_init(stack_a);
	//if not sorted, perform the algo
	return (EXIT_SUCCESS);
}
