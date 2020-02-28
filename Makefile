# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 14:56:43 by hrazani           #+#    #+#              #
#    Updated: 2020/02/27 20:13:06 by hrazani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
COR =		main.o\
			tools.o\
			parse.o\
			player.o\
			cursor.o\
			vm.o\
			debug.o

COR := $(addprefix src/vm/, $(COR))
#ALGORITHM := $(addprefix src/algorithm/, $(ALGORITHM))
FLAG = -Wall -Werror -Wextra 
OBJDIR = obj
CC = gcc
NAME = corewar
INCLUDE = includes/corewar.h

all : $(NAME)

$(NAME) : $(COR) $(INCLUDE) $(LIBFT)
		@$(CC) $(FLAG) $(COR) $(LIBFT) -o $(NAME)
		@echo "\x1b[32m---------- COMPILED SUCCESSFULLY ----------\x1b[0m"
$(LIBFT) :
		@make -C libft/
%.o : %.c
		@$(CC) $(FLAG) -c $< -o $@
clean :
		@rm -rf $(COR)
		@make clean -C libft/
		@echo "\x1b[32m---------- CLEANED SUCCESSFULLY ----------\x1b[0m"
fclean : clean
		@make fclean -C libft/
		@rm -rf $(NAME)
re : fclean all