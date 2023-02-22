# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#              #
#    Updated: 2023/02/17 15:58:22 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
INC			=	-I minitalk.h
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) server client

bonus: $(LIBFT) server client

server: server.o libft
	@$(CC) -o $@ $< -Llibft -lft $(INC)

client: client.o libft
	@$(CC) -o $@ $< -Llibft -lft $(INC)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re