# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 10:10:34 by iaschnei          #+#    #+#              #
#    Updated: 2023/02/12 12:08:17 by iaschnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
SRCS		=	main.c \
				parsing/input_parsing.c parsing/list_utils.c parsing/error_handling.c \
				parsing/map_parsing.c parsing/map_parsing_utils.c parsing/map_parsing_utils_bis.c \
				parsing/GNL/get_next_line.c parsing/GNL/get_next_line_utils.c \
				game_state/game_state.c game_state/game_start.c game_state/game_utils.c \
				game_state/game_exit.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS		=	$(SRCS:.c=.o)

CC			=	cc

INCL		=	so_long.h

FLAGS		=	-Wall -Wextra -Werror

MLXFLAGS	=	-LMLX -lmlx_Linux -lXext -lX11 -Lmlx -lm

NAME		=	so_long

MLX			=	./MLX/libmlx.a

COLOR_GREEN	=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

%.o: %.c
	@$(CC) -include so_long.h -I/usr/include -g -IMLX -O3 -c $< -o $@
	@echo "$(COLOR_BLUE) || Compiling ($<)...$(COLOR_END)"

all: $(NAME)

$(MLX):
	@cd ./MLX && sh ./configure && cd ..

$(NAME): $(OBJS) $(INCL) $(MLX)
	@$(CC) -I ./includes $(OBJS) -o $(NAME) $(MLXFLAGS)
	@echo "$(COLOR_GREEN) || Done !$(COLOR_END)"

clean:
	@rm -rf $(OBJS)
	@echo "$(COLOR_RED) || Cleaning files...$(COLOR_END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(COLOR_RED) || Cleaning library...$(COLOR_END)"

re: fclean all
	
.PHONY: re fclean all clean
