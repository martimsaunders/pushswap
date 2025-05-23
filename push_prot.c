/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_prot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:48:25 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/23 16:12:29 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_string(char *s1)
{
	int	i;

	i = 0;
	if (!*s1)
		return (1);
	while (s1[i])
	{
		while (s1[i] == ' ')
			i++;
		if (s1[i] == '+' || s1[i] == '-')
		{
			i++;
			if (s1[i] == '+' || s1[i] == '-')
				return (1);
		}
		while (s1[i] >= '0' && s1[i] <= '9')
		{
			i++;
			if ((s1[i] <= '0' && s1[i] >= '9') && (s1[i] != ' ' && s1[i]))
				return (1);
		}
		if (s1[i] != ' ' && s1[i])
			return (1);
	}
	return (0);
}

int	str_prot(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_string(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_dbls(t_list **stack)
{
	t_list	*current;
	t_list	*compare;

	if (!stack || !(*stack))
		return (1);
	current = *stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (compare->number == current->number)
				return (write(1, "DOUBLE NUMBERS ", 15), 1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}
