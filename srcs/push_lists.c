/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:58:48 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/29 11:33:00 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split_args(char **newstr)
{
	int	i;

	i = 0;
	while (newstr[i])
		free(newstr[i++]);
	free(newstr);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

static int	process_number(t_list **stack_a, char *str)
{
	long	num;
	t_list	*new_node;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	new_node = ft_lstnew((int)num);
	if (!new_node)
		return (free_stack(stack_a), 1);
	ft_lstadd_back(stack_a, new_node);
	return (0);
}

int	create_stack(t_list **stack_a, char **argv, int argc, int i)
{
	int		j;
	char	**split_args;

	while (++i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			continue ;
		if (ft_strchr(argv[i], ' '))
		{
			split_args = ft_split(argv[i], ' ');
			if (split_args[0] == NULL)
			{
				free_split_args(split_args);
				continue ;
			}
			j = 0;
			while (split_args[j])
				if (process_number(stack_a, split_args[j++]))
					return (free_split_args(split_args), 1);
			free_split_args(split_args);
		}
		else if (process_number(stack_a, argv[i]))
			return (1);
	}
	return (check_dbls(stack_a));
}
