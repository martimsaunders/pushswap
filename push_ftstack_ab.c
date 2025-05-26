/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ftstack_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:16:29 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/26 15:20:01 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_ab(t_list **stack_ab, int type)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (!stack_ab || !(*stack_ab) || !(*stack_ab)->next)
		return (0);
	first = *stack_ab;
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
	*stack_ab = second;
	if (type == 1)
		write(1, "sa\n", 3);
	if (type == 2)
		write(1, "sa\n", 3);
	return (1);
}

void	push_ab(t_list **stack_src, t_list **stack_dst, int type)
{
	t_list	*temp;

	if (!stack_src || !(*stack_src))
		return ;
	temp = *stack_src;
	*stack_src = temp->next;
	if (*stack_src)
		(*stack_src)->previous = NULL;
	temp->next = *stack_dst;
	if (*stack_dst)
		(*stack_dst)->previous = temp;
	temp->previous = NULL;
	*stack_dst = temp;
	update_indexes(stack_src);
	update_indexes(stack_dst);
	if (type == 1)
		write(1, "pb\n", 3);
	if (type == 2)
		write(1, "pa\n", 3);
}

int	rotate_ab(t_list **stack, int type)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	(*stack)->previous = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	update_indexes(stack);
	if (type == 1)
		write(1, "ra\n", 3);
	if (type == 2)
		write(1, "rb\n", 3);
	return (1);
}

int	reverse_rotate_ab(t_list **stack, int type)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->previous = last;
	last->previous->next = NULL;
	last->previous = NULL;
	*stack = last;
	update_indexes(stack);
	if (type == 1)
		write(1, "rra\n", 4);
	if (type == 2)
		write(1, "rrb\n", 4);
	return (1);
}
