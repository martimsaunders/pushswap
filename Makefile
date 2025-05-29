# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprazere <mprazere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 16:39:26 by mprazere          #+#    #+#              #
#    Updated: 2025/05/29 11:35:27 by mprazere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a
SRCS = srcs/push_lists.c \
srcs/push_prot.c \
srcs/push_split.c \
srcs/push_swap.c \
srcs/push_utils.c \
srcs/push_ftstack_ab.c \
srcs/push_ftstack_both.c \
srcs/push_sort2a5.c \
srcs/push_radix.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I libraries
EXEC = push_swap

all: $(EXEC)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo 'Biblioteca criada!'
	@echo 'Funções Compiladas!'

$(EXEC): $(NAME)
	@$(CC) $(CFLAGS) srcs/main.c -o $(EXEC) -L. -lpushswap
	@echo 'Executável $(EXEC) criado e pronto para uso!'

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXEC)
	@echo 'Biblioteca limpa!'

re: fclean all

.PHONY: all clean fclean re
