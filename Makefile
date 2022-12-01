# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/12/01 03:30:01 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -Isources

SOURCES_DIR = sources

BINARIES_DIR = binaries

SRC = $(SOURCES_DIR)/ft_printf.c \
	$(SOURCES_DIR)/ft_fun_conv_1.c \
	$(SOURCES_DIR)/ft_fun_conv_2.c \
	$(SOURCES_DIR)/ft_long_to_hexa.c \
	$(SOURCES_DIR)/ft_itoa.c \
	$(SOURCES_DIR)/ft_itoa_unsigned.c \
	$(SOURCES_DIR)/ft_itoa_hexa.c \
	$(SOURCES_DIR)/utils.c

OBJ = $(BINARIES_DIR)/ft_printf.o \
	$(BINARIES_DIR)/ft_fun_conv_1.o \
	$(BINARIES_DIR)/ft_fun_conv_2.o \
	$(BINARIES_DIR)/ft_long_to_hexa.o \
	$(BINARIES_DIR)/ft_itoa.o \
	$(BINARIES_DIR)/ft_itoa_unsigned.o \
	$(BINARIES_DIR)/ft_itoa_hexa.o \
	$(BINARIES_DIR)/utils.o

RM = rm -f

$(NAME) : $(BINARIES_DIR) $(OBJ)
	ar -rc $(NAME) $(OBJ)

$(BINARIES_DIR) :
	mkdir $(BINARIES_DIR)

$(BINARIES_DIR)/%.o : $(SOURCES_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -g3

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
