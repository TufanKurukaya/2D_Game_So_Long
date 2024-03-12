# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 18:45:47 by beeren            #+#    #+#              #
#    Updated: 2024/03/06 17:55:55 by tkurukay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c	\
ft_bzero.c		\
ft_isalnum.c	\
ft_isalpha.c	\
ft_isascii.c	\
ft_isdigit.c	\
ft_isprint.c	\
ft_memchr.c		\
ft_memcmp.c		\
ft_memmove.c	\
ft_memcpy.c		\
ft_memset.c		\
ft_strrchr.c	\
ft_itoa.c		\
ft_strchr.c		\
ft_strlcpy.c	\
ft_putchar_fd.c	\
ft_putstr_fd.c	\
ft_putendl_fd.c	\
ft_strdup.c		\
ft_calloc.c		\
ft_putnbr_fd.c	\
ft_strlen.c		\
ft_strncmp.c	\
ft_strtrim.c	\
ft_strnstr.c	\
ft_substr.c		\
ft_strjoin.c 	\
ft_split.c		\
ft_tolower.c	\
ft_toupper.c	\
ft_strlcat.c	\
ft_striteri.c	\
ft_strmapi.c	\
ft_printf.c		\
ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
