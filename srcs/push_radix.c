/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:55:01 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/29 11:32:57 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_max_bits(t_list *stack)
{
	int	number;
	int	bits;
	int	max_bits;

	if (!stack)
		return (0);
	max_bits = 0;
	while (stack)
	{
		number = stack->normalized;
		bits = 0;
		while (number > 0)
		{
			bits++;
			number >>= 1;
		}
		if (bits > max_bits)
			max_bits = bits;
		stack = stack->next;
	}
	return (max_bits);
}

static int	count_zeroandone(t_list *stack, int i, int bit)
{
	while (stack)
	{
		if ((stack->normalized >> i & 1) == bit)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	sorted_ab(t_list *stack, int type)
{
	if (!stack)
		return (0);
	if (type == 1)
	{
		while (stack->next)
		{
			if (stack->normalized > stack->next->normalized)
				return (0);
			stack = stack->next;
		}
	}
	else if (type == 2)
	{
		while (stack->next)
		{
			if (stack->normalized < stack->next->normalized)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

static void	push_and_rotate(t_list **a, t_list **b, int i, int type)
{
	int	size;
	int	count;
	int	aorb;

	if (type == 1)
		aorb = 0;
	if (type == 2)
		aorb = 1;
	count = 0;
	size = count_lst(*a);
	if (count_zeroandone(*a, i, aorb))
		return ;
	while (count++ < size)
	{
		if (sorted_ab(*a, 1) && sorted_ab(*b, 2))
		{
			while (*b)
				push_ab(b, a, 2);
			break ;
		}
		if (((*a)->normalized >> i & 1) == aorb)
			push_ab(a, b, type);
		else
			rotate_ab(a, type);
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	max_bits;

	i = 0;
	max_bits = count_max_bits(*a);
	while (i < max_bits)
	{
		push_and_rotate(a, b, i, 1);
		i++;
		push_and_rotate(b, a, i, 2);
		if (i == max_bits)
			while (*b)
				push_ab(b, a, 2);
		if (is_sorted(*a))
			return ;
	}
}
