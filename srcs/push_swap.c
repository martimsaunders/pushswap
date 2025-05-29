/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:16:50 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/29 11:32:51 by mprazere         ###   ########.fr       */
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

int	count_lst(t_list *stack)
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

int	is_sorted(t_list *stack)
{
	if (!stack)
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
	int	lst_size;

	lst_size = count_lst(*a);
	if (lst_size == 1)
	{
		write (2, "Error\n", 6);
		return ;
	}
	if (is_sorted(*a))
		return ;
	normalize_lst(a);
	if (lst_size == 2)
		sort_two(a);
	else if (lst_size == 3)
		sort_three(a);
	else if (lst_size == 4)
		sort_fourtofive(a, b, 4, lst_size);
	else if (lst_size == 5)
		sort_fourtofive(a, b, 5, lst_size);
	else
		radix_sort(a, b);
}
