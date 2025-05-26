/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:59:23 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/26 16:31:56 by mprazere         ###   ########.fr       */
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
	if (create_stack(&a, argv, argc))
		return (free_stack(&a), write(1, "ALLOCATION ERROR\n", 17), 1);
	temp = a;
	printf("STACK CRIADO\n");
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	}
	/* push_ab(&a, &b, 1);
	push_ab(&a, &b, 1);
	push_ab(&a, &b, 1);
	temp = a;
	printf("STACK A\n");
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	}
	temp = b;
	printf("STACK B\n");
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	}
	reverse_rotate_both(&a, &b);
	temp = a;
	printf("STACK A\n");
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	}
	temp = b;
	printf("STACK B\n");
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	} */
	ordenate_lst(&a, &b);
	temp = a;
	printf("STACK A\n");
	while (temp)
	{
		printf("[%d]%d\n", temp->index, temp->number);
		temp = temp->next;
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
