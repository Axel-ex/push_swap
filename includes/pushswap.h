/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:30:08 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/21 13:26:21 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_node
{
	int				data;
	int				position;
	int				price;
	bool			above_median;
	struct s_node	*target_node;
	struct s_node	*next;
}	t_node;

/// ============================================================================
// SPLIT.C
// =============================================================================
/**
 * @brief take a string and split it into null terminated strings
 * on the specified separator.
 * 
 * @param s string to split
 * @param sep separator to split on
 * @return char** 
 */
char	**split(char *s, char sep);

// =============================================================================
// INIT_CHECK.C
// =============================================================================
/**
 * @brief Initialise the stack (linked list) while checking for 
 * duplicates or values outside of INT range.
 * 
 * @param stack to init
 * @param argv containing the values to sort
 * @param split_flag if true, argv was alloc by split and needs free
 */
void	stack_init(t_node **stack, char **argv, bool split_flag);

/**
 * @brief look for invalid char.
 * 
 * @param argv 
 * @return true all char are numbers
 * @return false 
 */
bool	check_valid_char(char **argv);

/**
 * @brief check if the stack is sorted.
 * 
 * @param stack 
 * @return true the stack is sorted
 * @return false 
 */
bool	is_sorted(t_node *stack);

// =============================================================================
// EXIT.C
// =============================================================================
/**
 * @brief exit the program by freeing the appropriated blocks of memory.
 * 
 * @param stack stack to free
 * @param argv 
 * @param split_flag if true, argv needs free
 */
void	exit_error(t_node **stack, char **argv, bool split_flag);

/**
 * @brief free all the nodes and the pointer to stack.
 * 
 * @param stack to free
 */
void	destroy_stack(t_node **stack);

/**
 * @brief free all the element contained in argv.
 * 
 * @param argv 
 */
void	free_matrix(char **argv);

// =============================================================================
// STACK_UTILS.C
// =============================================================================
/**
 * @brief return the stack size.
 * 
 * @param stack 
 * @return stack_size 
 */
int		get_stack_size(t_node *stack);

/**
 * @brief add a node at the end of the stack.
 * 
 * @param value held by the node
 * @param stack to add to
 */
void	node_add_back(long value, t_node **stack);

/**
 * @brief return the last node. if second_last true,
 * return the second to last node.
 * 
 * @param stack 
 * @param second_last 
 * @return t_node* 
 */
t_node	*get_last_node(t_node *stack, bool second_last);

/**
 * @brief return the node holding the highest value.
 * 
 * @param stack 
 * @return t_node* adress of the highest node
 */
t_node	*get_highest(t_node *stack);

/**
 * @brief return the node holding the smallest value.
 * 
 * @param stack 
 * @return t_node* adress of the smallest node.
 */
t_node	*get_smallest(t_node *stack);

// =============================================================================
// SWAP.C
// =============================================================================
/**
 * @brief swap the two first element of stack_a. 
 * 
 * @param stack
 * @param silent if true, no message is printed on stdout 
 */
void	sa(t_node **stack, bool silent);

/**
 * @brief swap the two first element of stack_b.
 * 
 * @param stack 
 * @param silent if true, no message is printed on stdout 
 */
void	sb(t_node **stack, bool silent);

/**
 * @brief swap the first element of both stacks.
 * 
 * @param stack_a 
 * @param stack_b 
 * @param silent if true, no message is printed on stdout 
 */
void	ss(t_node **stack_a, t_node **stack_b, bool silent);

// =============================================================================
// PUSH.C
// =============================================================================
/**
 * @brief push first element of stack_b to stack_a.
 * 
 * @param stack_a 
 * @param stack_b 
 * @param silent if true, no message is printed on stdout 
 */
void	pa(t_node **stack_a, t_node **stack_b, bool silent);

/**
 * @brief push first element of stack_a to stack_b.
 * 
 * @param stack_a 
 * @param stack_b 
 * @param silent if true, no message is printed on stdout 
 */
void	pb(t_node **stack_a, t_node **stack_b, bool silent);

// =============================================================================
// ROTATE.C
// =============================================================================
/**
 * @brief shift stack_a up of one element. if reverse_flag true
 * shift stack_a down from one element.
 * 
 * @param stack_a 
 * @param reverse_flag if true, shift down
 * @param silent if true, no message is printed on stdout 
 */
void	ra(t_node **stack_a, bool reverse_flag, bool silent);

/**
 * @brief shift stack_b up of one element. if reverse_flag true
 * shift stack_b down from one element.
 * 
 * @param stack_b 
 * @param reverse_flag if true, shift down
 * @param silent if true, no message is printed on stdout 
 */
void	rb(t_node **stack_b, bool reverse_flag, bool silent);

/**
 * @brief shift both stacks up until the cheapest node is on top of stack_b
 * or the target of the cheapest is on top of stack_a. if reverse_flag true,
 * shift both stacks down until cheapest or target cheapest is toped
 * 
 * @param stack_a
 * @param stack_b
 * @param reverse_flag if true, shift down
 */
void	rotate_both(t_node **stack_a, t_node **stack_b, bool reverse_flag);

// =============================================================================
// TINY_SORT.C
// =============================================================================
/**
 * @brief sort a stack of 3 nodes.
 * 
 * @param stack 
 */
void	tiny_sort(t_node **stack);

/**
 * @brief sort a stack of 5 nodes.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	small_sort(t_node **stack_a, t_node **stack_b);

// =============================================================================
// INIT_NODES.C
// =============================================================================
/**
 * @brief set index of nodes and raise above_median flag if needed.
 * 
 * @param stack 
 */
void	set_position(t_node *stack);

/**
 * @brief Associate every nodes of stack_b to a target in stack_a. The target
 * is define as a bigger node with the smallest difference of value.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	set_target_node(t_node *stack_a, t_node *stack_b);

/**
 * @brief Calculate the push cost of every nodes based on their positions
 * and on the positions of their target nodes.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	set_price(t_node *stack_a, t_node *stack_b);

/**
 * @brief set positions, targets, and prices.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	init_nodes(t_node **stack_a, t_node **stack_b);

/**
 * @brief Get the cheapest node to push.
 * 
 * @param stack 
 * @return t_node* 
 */
t_node	*get_cheapest(t_node *stack);

// =============================================================================
// MID_POINT.C
// =============================================================================
/**
 * @brief transfer elements from stack_a to stack_b by sorting in the
 * backend the array and finding the value positioned in the middle.
 * elements smaller than the middle value are transfered to stack_b.
 * Operation is done until 3 numbers remain on the stack_a.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	transfer_to_b(t_node **stack_a, t_node **stack_b);

// =============================================================================
// MID_POINT_UTIL.C
// =============================================================================
/**
 * @brief Get the first occurence of the number smaller than middle point.
 * 
 * @param stack_a 
 * @param middle_point of the sorted array
 * @return int index of the first occurence
 */
int		get_first_occur(t_node *stack_a, int middle_point);

/**
 * @brief Get the last occurence of the number smaller than middle point.
 * 
 * @param stack_a 
 * @param middle_point 
 * @return int 
 */
int		get_last_occur(t_node *stack_a, int middle_point);

/**
 * @brief got to node positioned at head + index.
 * 
 * @param stack_a 
 * @param index 
 * @return t_node* 
 */
t_node	*got_to_node(t_node *stack_a, int index);

// =============================================================================
// PUSH_SWAP.C
// =============================================================================
/**
 * @brief Push the elements of stack_a on stack_b until 3 remain.
 * sort them by tiny sort and then repetitively calculate the 
 * move cost of each nodes to then move the cheapest.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	push_swap(t_node **stack_a, t_node **stack_b);

/**
 * @brief rotate the stacks until the cheapest is on top of stack_b
 * and the target of this cheapest is on top of stack_a.
 * 
 * @param stack 
 * @param top cheapest node to top
 * @param stack_name 'a' or 'b'
 */
void	finish_rotation(t_node **stack, t_node *top, char stack_name);

// =============================================================================
// DEBUG.C
// =============================================================================
/**
 * @brief read the stack and print it's content on standard output.
 * 
 * @param stack 
 * @param flag_a if true, print appropriated name
 */
void	read_stack(t_node *stack, bool flag_a);

#endif