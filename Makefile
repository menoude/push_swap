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
SRC = error.c args.c stack.c instructions.c operations.c \
			sort.c subset.c clean.c content.c print.c
BINARIES = $(SRC:.c=.o)
CC = gcc -Wall -Werror -Wextra #enlever le -g

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(DIR_LIB) checker.o $(BINARIES)
	$(CC) checker.o $(BINARIES) -o $(NAME_1) -I libft/includes -L $(DIR_LIB) -lft

$(NAME_2): $(DIR_LIB) push_swap.o $(BINARIES)
	$(CC) push_swap.o $(BINARIES) -o $(NAME_2) -I libft/includes -L $(DIR_LIB) -lft

$(DIR_LIB): libft.a

libft.a:
	$(MAKE) -C $(DIR_LIB)

%.o: %.c
	$(CC) -c $<

clean:
	$(MAKE) -C $(DIR_LIB) clean
	/bin/rm -f $(BINARIES) checker.o push_swap.o
fclean: clean
	$(MAKE) -C $(DIR_LIB) fclean
	/bin/rm -f $(NAME_1) $(NAME_2)
re: fclean all

.PHONY: all clean fclean re%
