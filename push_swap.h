/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:01:11 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/26 16:30:16 by mprazere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				number;
	int				normalized;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

char				**ft_split(char const *s, char c);
long				ft_atol(const char *nptr);
char				*ft_strchr(const char *s, int c);
int					str_prot(int argc, char **argv);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				free_stack(t_list **stack);
int					create_stack(t_list **stack_a, char **argv, int argc);
int					check_dbls(t_list **stack);
int					swap_ab(t_list **stack_a, int type);
void				swap_both(t_list **a, t_list **b);
void				push_ab(t_list **stack_src, t_list **stack_dst, int type);
void				update_indexes(t_list **stack);
int					rotate_ab(t_list **stack, int type);
void				rotate_both(t_list **a, t_list **b);
int					reverse_rotate_ab(t_list **stack, int type);
void				reverse_rotate_both(t_list **a, t_list **b);
void				sort_two(t_list **stack);
void				sort_three(t_list **stack);
void				sort_fortofive(t_list **stack_a, t_list **stack_b, int size,
						int lst_size);
void				ordenate_lst(t_list **a, t_list **b);
int					is_sorted(t_list *stack);

#endif