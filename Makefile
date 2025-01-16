# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025-01-16 15:52:35 by rmunoz-c          #+#    #+#              #
#    Updated: 2024-01-16 15:52:35 by rmunoz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

MLX_PATH=mlx
MLX_LIB=mlx
MLX_LIBPATH=mlx/libmlx.a
LIBFT_DIR= libft
LIBFT = $(LIBFT_DIR)/libft.a

CC= cc
CFLAGS= -Wall -Werror -Wextra -g

SRC=		src/end_game.c \
			src/key_hook.c \
			src/map_parse.c \
			src/main.c \
			src/movement.c \
			src/path_finder.c \
			src/read_map.c \
			src/set_images.c

OBJ= $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MLX_LIBPATH)
	$(CC) $(OBJ) $(LIBFT) -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz -o $(NAME) $(CFLAGS)


%.o: %.c so_long.h
	$(CC) $(CFLAGS) -o $@ $< -c

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX_LIBPATH):
	$(MAKE) -sC $(MLX_PATH)

clean:
	rm -f $(OBJ)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL: all

.PHONY: all clean fclean re
