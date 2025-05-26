/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:16:50 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/26 16:31:29 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normalize_lst(t_list **stack)
{
	t_list	*temp;
	t_list	*current;
	int		rank;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		rank = 0;
		temp = *stack;
		while (temp)
		{
			if (current->number > temp->number)
				rank++;
			temp = temp->next;
		}
		current->normalized = rank;
		current = current->next;
	}
}

/* static int	count_max_bits(t_list *stack)
{
	int		number;
	int		bits;
	int		max_bits;

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
} */

static int	count_lst(t_list *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

//radix

int	is_sorted(t_list *stack)
{
	if(!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ordenate_lst(t_list **a, t_list **b)
{
	int lst_size;
	//int	max_bits;
	
	if (is_sorted(*a))
		return ;
	lst_size = count_lst(*a);
	normalize_lst(a);
	if (lst_size == 2)
		sort_two(a);
	else if (lst_size == 3)
		sort_three(a);
	else if (lst_size == 4)
		sort_fortofive(a, b, 4, lst_size);
	else if (lst_size == 5)
		sort_fortofive(a, b, 5, lst_size);
}
