/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_tutor_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:56:16 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/18 14:20:48 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int                data;
    int                pos;
    struct s_node    *next;
    struct s_node    *prev;
} t_node;

t_node    *find_last_node(t_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void    append_node(long nb, t_node **stack)
{
    t_node    *new;
    t_node    *last;

    new = (t_node *)malloc(sizeof(t_node));
    if (!new)
        return ;
    new->data = (int)nb;
    new->next = NULL;
    if (!*stack)
    {
        *stack = new;
        new->prev = NULL;
    }
    else
    {
        last = find_last_node(*stack);
        last->next = new;
        new->prev = last;
    }
}

void    swap(t_node **stack)
{
    t_node    *buf;

    if (!stack || !*stack)
        return ;
    buf = *stack;
    *stack = *stack->next;
    *stack->next = buf;
}

static void	push(t_node **stack_from, t_node **stack_to)
{
	if (!stack_from || !*stack_from || !stack_to || !*stack_to)
		return ;
	(*stack_from)->next->prev = NULL;
	(*stack_from)->next = *stack_to;
	(*stack_to)->prev = *stack_from;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

int main() {

	t_node *stack_a = NULL;
	t_node *stack_b = NULL;
	int i = 30;

	while (i > 0)
	{
		append_node(i, &stack_a);
		append_node(i, &stack_b);
		i -= 5;
	}
	swap(&stack);
	pa(stack_a, stack_b);
	return 0;
}