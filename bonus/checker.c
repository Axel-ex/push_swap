/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:53:32 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/17 10:26:41 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_line(char *line)
{
	if (!ft_strncmp("ra", line, 3) || !ft_strncmp("rb", line, 3)
		|| !ft_strncmp("rra", line, 3) || !ft_strncmp("rrb", line, 3)
		|| !ft_strncmp("rr", line, 3) || !ft_strncmp("rrr", line, 4)
		|| !ft_strncmp("sa", line, 3) || !ft_strncmp("sb", line, 3)
		|| !ft_strncmp("ss", line, 3) || !ft_strncmp("pa", line, 3)
		|| !ft_strncmp("pb", line, 3))
		return (1);
	return (0);
}

void	execute_command(char *line, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp("ra", line, 3))
		ra(stack_a, false, true);
	else if (!ft_strncmp("rb", line, 3))
		rb(stack_b, false, true);
	else if (!ft_strncmp("rra", line, 4))
		ra(stack_a, true, true);
	else if (!ft_strncmp("rrb", line, 4))
		rb(stack_b, true, true);
	else if (!ft_strncmp("rr", line, 3))
		rotate_both(stack_a, stack_b, false);
	else if (!ft_strncmp("rrr", line, 4))
		rotate_both(stack_a, stack_b, true);
	else if (!ft_strncmp("pa", line, 3))
		pa(stack_a, stack_b, true);
	else if (!ft_strncmp("pb", line, 3))
		pb(stack_a, stack_b, true);
	else if (!ft_strncmp("sa", line, 3))
		sa(stack_a, true);
	else if (!ft_strncmp("sb", line, 3))
		sb(stack_b, true);
	else if (!ft_strncmp("ss", line, 3))
		ss(stack_a, stack_b, true);
}

void	read_command(t_node **stack_a, t_node **stack_b, int i)
{
	char	*line;
	char	buf;

	line = ft_calloc(sizeof(char *), 4);
	while (read(0, &buf, 1))
	{
		if (i >= 3 || buf == '\n')
		{
			line[i] = '\0';
			if (!check_line(line))
			{
				free(line);
				destroy_stack(stack_a);
				destroy_stack(stack_b);
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			execute_command(line, stack_a, stack_b);
			free(line);
			line = ft_calloc(sizeof(char *), 4);
			i = 0;
		}
		else
			line[i++] = buf;
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
	stack_init(&stack_a, argv, argc == 2);
	read_command(&stack_a, &stack_b, 0);
	if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	return (EXIT_SUCCESS);
}
