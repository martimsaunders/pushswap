# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 16:39:26 by mprazere          #+#    #+#              #
#    Updated: 2025/05/23 18:11:46 by mprazere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a
SRCS = push_lists.c push_prot.c push_split.c push_swap.c push_utils.c push_ftstack_a.c push_ftstack_both.c push_ftstack_b.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
EXEC = pushswap

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo 'Biblioteca criada!'
	@echo 'Funções Compiladas!'

$(EXEC): $(NAME)
	$(CC) $(CFLAGS) main.c -o $(EXEC) -L. -lpushswap

test: $(EXEC)
	@echo 'Executável $(EXEC) criado e pronto para uso!'

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXEC)
	@echo 'Biblioteca limpa!'

re: fclean all

.PHONY: all clean fclean re test
