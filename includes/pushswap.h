/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:30:08 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/21 16:35:27 by achabrer         ###   ########.fr       */
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
	int				data;
	int				pos;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* Split */
char	**split(char *s, char sep);
int		count_words(char *s, char sep);

/* Init_checks */
void	stack_init(t_node **stack, char **argv, bool split_flag);
bool	check_valid_char(char **argv);
bool	is_sorted(t_node *stack);

/* Exit */
void	exit_error(t_node **stack, char **argv, bool split_flag);
void	destroy_stack(t_node **stack);
void	free_matrix(char **argv);

/*  Stack utils */
int		get_stack_size(t_node *stack);
void	node_add_back(long nb, t_node **stack);
t_node	*get_last_node(t_node *stack);
t_node	*get_highest(t_node *stack);
t_node	*get_smallest(t_node *stack);

/* Commands */
/* Swap */
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);

/* Push */
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

/* Rotate */
void	ra(t_node **stack_a, bool reverse_flag);
void	rb(t_node **stack_b, bool reverse_flag);

/* Algo*/
/* tiny sort*/
void	tiny_sort(t_node **stack);

/* init_nodes */
void	get_position(t_node *stack);
void	get_target_node(t_node *stack_a, t_node *stack_b);
void	get_price(t_node *stack_a, t_node *stack_b);
void	get_cheapest(t_node *stack);
void	init_nodes(t_node **stack_a, t_node **stack_b);

/* Push_swap */
void	push_swap(t_node **stack_a, t_node **stack_b);

/* Debug */
void	read_stack(t_node *stack, bool flag_a);

#endif