# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/12/21 08:11:01 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -Isources

SOURCES_DIR = sources

BINARIES_DIR = binaries

SRC = $(SOURCES_DIR)/ft_printf.c \
	$(SOURCES_DIR)/ft_fun_conv_char.c \
	$(SOURCES_DIR)/ft_fun_conv_decimal.c \
	$(SOURCES_DIR)/ft_fun_conv_hex.c

#SRCS= $(addprefix $(SOURCES_DIR)/,$(SRC))

OBJ = $(BINARIES_DIR)/ft_printf.o \
	$(BINARIES_DIR)/ft_fun_conv_char.o \
	$(BINARIES_DIR)/ft_fun_conv_decimal.o \
	$(BINARIES_DIR)/ft_fun_conv_hex.o

RM = rm -f

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

$(BINARIES_DIR) :
	mkdir $(BINARIES_DIR)

$(BINARIES_DIR)/%.o : $(SOURCES_DIR)/%.c $(SOURCES_DIR)/ft_printf.h | $(BINARIES_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
