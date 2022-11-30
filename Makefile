# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/11/30 16:25:28 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -Isources

SRC = sources/ft_printf.c \
	sources/ft_fun_conv_1.c \
	sources/ft_fun_conv_2.c \
	sources/ft_long_to_hexa.c \
	sources/ft_itoa.c

OBJ = binaries/ft_printf.o \
	binaries/ft_fun_conv_1.o \
	binaries/ft_fun_conv_2.o \
	binaries/ft_long_to_hexa.c \
	binaries/ft_itoa.c

RM = rm -f

$(NAME) : binaries $(OBJ)
	ar -rc $(NAME) $(OBJ)

binaries :
	mkdir binaries

binaries/%.o : sources/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -g3

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
