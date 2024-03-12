# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 17:44:32 by tkurukay          #+#    #+#              #
#    Updated: 2024/03/09 17:50:03 by tkurukay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC				=	src/map_control.c	\
					src/map_control1.c	\
					src/path_finding.c	\
					src/so_long.c	\
					src/play_game.c	\
					src/exit.c	\

LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	minilibx
OBJ				=	$(SRC:.c=.o)
all:	$(NAME)

$(NAME): mlx $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

$(LIBFT):
	make -C $(LIBFT_PATH) all

mlx:
	make -C $(MINILIBX_PATH) all

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean


fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clean fclean re libft
.SECONDARY:	mlx
