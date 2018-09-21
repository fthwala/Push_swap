# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fthwala <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 12:54:47 by fthwala           #+#    #+#              #
#    Updated: 2017/11/29 13:16:35 by fthwala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = push_swap

NAME_2 = checker

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBS = libft/libft.a

INCLUDES = push_swap.h

SRC =  stack_op.c sort.c push.c operations.c operations_1.c\
	   check.c check1.c check2.c verify.c

.SILENT : $(all)
all: $(NAME_1) $(NAME_2)

$(NAME_1):
	@$(MAKE) -C libft/ re
	@$(CC) -o $(NAME_1) $(SRC) push_swap.c $(CFLAGS) $(LIBS)

$(NAME_2):
	@$(MAKE) -C libft/ re
	@$(CC) -o $(NAME_2) $(SRC) checker.c $(CFLAGS) $(LIBS)

norme: 
	@echo "\t\t<<<< Norminette all .c files >>>>\n"
	find . -name '*.c' -exec norminette {} \;
	@echo "\t\t<<<< Norminette all .h files >>>>\n"
	find . -name '*.h' -exec norminette {} \;

clean:
	$(MAKE) -C libft/ clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all
	$(MAKE) -C libft fclean re

