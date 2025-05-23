/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:01:11 by mprazere          #+#    #+#             */
/*   Updated: 2025/05/23 18:10:46 by mprazere         ###   ########.fr       */
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
int					swap_a(t_list **stack_a, int type);
void				swap_both(t_list **a, t_list **b);
int					swap_b(t_list **stack_b, int type);
#endif