/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ftstack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:07:52 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/23 18:15:55 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_b(t_list **stack_b, int type)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->previous = first;
	first->previous = second;
	second->previous = NULL;
	temp = first->index;
	first->index = second->index;
	second->index = temp;
	*stack_b = second;
	if (type == 1)
		write(1, "sa\n", 3);
	return (2);
}