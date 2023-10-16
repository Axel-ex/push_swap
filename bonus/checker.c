/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:53:32 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/16 14:15:46 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_line(char *line)
{
	while (*line)
	{
		if (*line == 'a')
			return (1);
		line++;
	}
	return (0);
}

void	read_command(void)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!check_line(line))
		{
			free(line);
			break ;
		}
		free(line);
	}
}

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
	read_command();
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (EXIT_SUCCESS);
}
