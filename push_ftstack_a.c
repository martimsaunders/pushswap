/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ftstack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:16:29 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/23 18:15:47 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_list **stack_a, int type)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	first = *stack_a;
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
	*stack_a = second;
	if (type == 1)
		write(1, "sa\n", 3);
	return (1);
}
