/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:59:23 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/29 11:33:20 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || str_prot(argc, argv) || (argc == 2 && !argv[1][0]))
		return (write(2, "Error\n", 6), 1);
	if (create_stack(&a, argv, argc, 0))
		return (free_stack(&a), write(2, "Error\n", 6), 1);
	ordenate_lst(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
