# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meyami <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 22:14:03 by meyami            #+#    #+#              #
#    Updated: 2018/01/05 22:14:06 by meyami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker
NAME_2 = push_swap
DIR_LIB = libft
#HEADER = push_swap.h
SRC_1 = checker.c args.c stack.c instructions.c operations.c
SRC_2 = push_swap.c
BINARIES_1 = $(SRC_1:.c=.o)
BINARIES_2 = $(SRC_2:.c=.o)
CC = gcc -g -Wall -Werror -Wextra #enlever le -g

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(DIR_LIB) $(BINARIES_1)
	$(CC) -g $(BINARIES_1) -o $(NAME_1) -I libft/includes -L $(DIR_LIB) -lft

$(NAME_2): $(DIR_LIB) $(BINARIES_2)
	$(CC) -g $(BINARIES_2) -o $(NAME_2) -I libft/includes -L $(DIR_LIB) -lft

$(DIR_LIB): libft.a

libft.a:
	$(MAKE) -C $(DIR_LIB)

%.o: %.c
	$(CC) -c $<

clean:
	$(MAKE) -C $(DIR_LIB) clean
	/bin/rm -f $(BINARIES_1) $(BINARIES_2)
fclean: clean
	$(MAKE) -C $(DIR_LIB) fclean
	/bin/rm -f $(NAME_1) $(NAME_2)
re: fclean all

.PHONY: all clean fclean re%
