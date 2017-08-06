# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/31 14:23:31 by jnederlo          #+#    #+#              #
#    Updated: 2017/08/05 18:54:47 by jnederlo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	filler
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -I includes
LIBRARY		=	libft
LIBRARY_B	=	libft/build
LIB_A		=	libft.a
FILES		=	fib_q.c \
				fibonacci.c \
				ft_filler.c \
				print_grid.c \
				setup.c \
				take_piece.c \
				update_map.c \

MESS_BLANK	=	@echo ""
MESS_LIBRARY=	@echo "\033[35m\033[1m**	COMPILING LIBRARY	**\033[0m"
MESS_SUCCESS=	@echo "\033[92m\033[1m**	Yea, Science Bitch!!	**\033[0m"
MESS_EXEC	=	@echo "\033[1m\033[33m**	COMPILING EXECUTABLE	**\033[0m"

SOURCES		=	$(addprefix srcs/, $(FILES))
OBJECTS		=	$(addprefix build/, $(FILES:.c=.o))

.PHONY: clean fclean all re

all:	$(NAME)

clean:
	@rm -rf build
	@rm -rf $(LIBRARY_B)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_A)

re: fclean all

$(NAME): $(OBJECTS)
	$(MESS_BLANK)
	$(MESS_LIBRARY)
	@make -C $(LIBRARY)
	$(MESS_BLANK)
	$(MESS_EXEC)
	$(MESS_BLANK)
	@$(CC) -o $@ $(FLAGS) $(OBJECTS) -L $(LIBRARY) -lft -fsanitize=address
	$(MESS_SUCCESS)
	$(MESS_BLANK)

build:
	@mkdir build/

build/%.o: srcs/%.c | build
	@$(CC) $(FLAGS) -c $< -o $@