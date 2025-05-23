/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:59:23 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/23 18:15:59 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;

	a = NULL;
	b = NULL;
	(void)b;
	if (argc < 2 || str_prot(argc, argv) || (argc == 2 && !argv[1][0]))
		return (write(1, "ERRO\n", 5), 1);
	if (create_stack(&b, argv, argc))
		return (free_stack(&b), write(1, "ALLOCATION ERROR\n", 17), 1);
	temp = b;
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	}
	swap_both(&a, &b);
	temp = b;
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	}
	free_stack(&a);
	return (0);
}
