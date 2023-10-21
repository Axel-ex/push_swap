/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:20:05 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/21 13:36:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	bubble_sort(int *to_sort, int size)
{
	int	i;
	int	buf;

	i = 1;
	while (i < size)
	{
		if (to_sort[i] < to_sort[i - 1])
		{
			buf = to_sort[i];
			to_sort[i] = to_sort[i -1];
			to_sort[i - 1] = buf;
			i = 1;
		}
		i++;
	}
}

int	*get_sorted_array(t_node *stack)
{
	int	*sorted;
	int	i;
	int	size;

	i = 0;
	size = get_stack_size(stack);
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	while (i < size)
	{
		sorted[i] = stack->data;
		stack = stack->next;
		i++;
	}
	bubble_sort(sorted, size);
	return (sorted);
}

void	decide_rotate(t_node **stack_a, int middle_point)
{
	int	first_occur;
	int	last_occur;

	first_occur = get_first_occur(*stack_a, middle_point);
	last_occur = get_last_occur(*stack_a, middle_point);
	if (first_occur < last_occur)
	{
		while (first_occur--)
			ra(stack_a, false, false);
	}
	else
	{
		while (last_occur--)
			ra(stack_a, true, false);
	}
}

void	transfer_to_b(t_node **stack_a, t_node **stack_b)
{
	int	*arr_sorted;
	int	middle_point;
	int	to_move;

	while (get_stack_size(*stack_a) > 3)
	{
		arr_sorted = get_sorted_array(*stack_a);
		middle_point = arr_sorted[get_stack_size(*stack_a) / 2];
		to_move = get_stack_size(*stack_a) / 2;
		while (to_move-- > 0)
		{
			if ((*stack_a)->data < middle_point)
				pb(stack_a, stack_b, false);
			else
				decide_rotate(stack_a, middle_point);
		}
		free(arr_sorted);
	}
}
