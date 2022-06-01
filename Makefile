# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 10:21:55 by aricholm          #+#    #+#              #
#    Updated: 2022/06/01 12:29:46 by aricholm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_LIBFT = libft
NAME = cub3D
LIBFT = $(PATH_LIBFT)/libft.a
OBJ = obj
SRC = src
SRCS =	cub3d.c\
		parser.c\
		add_texture.c\
		get_map.c\
		validate.c\
		draw_line.c\
		raycast.c\
		move.c\
		keypress.c\
		init_textures.c

OBJS     = $(SRCS:%.c=$(OBJ)/%.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -lm

OS:= $(shell uname -s)
ifeq ($(OS),Darwin)
	MLXFLAGS = -I mlx_mac mlx_mac/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit
	INCDIR = mac
	CLEANUP = cleanup_mac.c
endif
ifeq ($(OS),Linux)
	MLXFLAGS = -I mlx_linux mlx_linux/libmlx.a -L/usr/X11/lib -I/opt/X11/include -lXext -lX11 -lm -lz -g
	INCDIR = linux
	CLEANUP = cleanup_linux.c
endif

CLEANOBJ     = $(CLEANUP:%.c=$(OBJ)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(CLEANOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(CLEANOBJ) $(LIBFT) $(LFLAGS) -o $(NAME) $(MLXFLAGS)

$(LIBFT):	
	@$(MAKE) -C $(PATH_LIBFT)

$(OBJS): $(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -I $(INCDIR) -o $@ $<

$(CLEANOBJ): $(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -I $(INCDIR) -o $@ $<

clean:
	rm -fr $(OBJ)
	@$(MAKE) clean -C $(PATH_LIBFT)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(PATH_LIBFT)


re: fclean all

.PHONY: all clean fclean re