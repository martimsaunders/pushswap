/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort2a5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:01:07 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/26 16:37:50 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	swap_ab(stack, 1);
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
	if (a < b && a < c && b > c)
	{
		reverse_rotate_ab(stack, 1);
		swap_ab(stack, 1);
	}
	else if (a > b && a < c && b < c)
		swap_ab(stack, 1);
	else if (a < b && a > c && b > c)
		reverse_rotate_ab(stack, 1);
	else if (a > b && a > c && b < c)
		rotate_ab(stack, 1);
	else if (a > b && b > c)
	{
		rotate_ab(stack, 1);
		swap_ab(stack, 1);
	}
}

static int	find_position(t_list *stack, int norm_value)
{
	int	pos;

	pos = 0;
	while (stack && stack->normalized != norm_value)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	sort_fortofive(t_list **stack_a, t_list **stack_b, int size,
		int lst_size)
{
	int	pos;
	int	to_push;
	int	i;
	int rotations;

	i = 0;
	to_push = size - 3;
	while (i < to_push)
	{
		pos = find_position(*stack_a, i);
		rotations = lst_size - pos;
		if (pos <= lst_size / 2 && pos > 0)
			while (pos-- > 0)
				rotate_ab(stack_a, 1);
		else if (pos > lst_size / 2)
			while (rotations-- > 0)
				reverse_rotate_ab(stack_a, 1);
		push_ab(stack_a, stack_b, 1);
		i++;
		lst_size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		push_ab(stack_b, stack_a, 2);
}