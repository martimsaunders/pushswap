/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ftstack_both.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:18:10 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/26 11:36:48 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_list **a, t_list **b)
{
	int i;
	int j;

	i = swap_ab(a, 0);
	j = swap_ab(b, 0);
	if (i == 1 && j == 0)
		write(1, "sa\n", 3);
	if (i == 0 && j == 1)
		write(1, "sb\n", 3);
	if (i + j == 2)
		write(1, "ss\n", 3);
}

void	rotate_both(t_list **a, t_list **b)
{
	int i;
	int j;

	i = rotate_ab(a, 0);
	j = rotate_ab(b, 0);
	if (i == 1 && j == 0)
		write(1, "ra\n", 3);
	if (i == 0 && j == 1)
		write(1, "rb\n", 3);
	if (i + j == 2)
		write(1, "rr\n", 3);
}

void	reverse_rotate_both(t_list **a, t_list **b)
{
	int i;
	int j;

	i = reverse_rotate_ab(a, 0);
	j = reverse_rotate_ab(b, 0);
	if (i == 1 && j == 0)
		write(1, "rra\n", 4);
	if (i == 0 && j == 1)
		write(1, "rrb\n", 4);
	if (i + j == 2)
		write(1, "rrr\n", 4);
}