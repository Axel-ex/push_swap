/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:30:08 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/11 15:51:03 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "../Libft/libft.h"

typedef struct s_node
{
	int				value;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* Checks */
long	*argv_to_int(char **argv, int argc);
bool	check_valid(char **argv, int argc);

/* Exit */
void	exit_error(void);
void	destroy_stacks(t_node *stack_a, t_node *stack_b);
void	destroy_argv(char **argv, int argc);

/* Split */
char	**split(char *s, char sep);
int		count_words(char *s, char sep);

/* Utils */
long	ft_atol(const char *s);
bool	is_sorted(char **argv, int argc);


#endif