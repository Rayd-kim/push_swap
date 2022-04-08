# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:06:10 by youskim           #+#    #+#              #
#    Updated: 2022/04/07 16:14:05 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
W = -Wall -Wextra -Werror
FILE = algorithm.c get_next_line_utils.c get_next_line.c push_swap.c operation_a.c \
		operation_b.c operation_ab.c \
		../push_swap/ft_atoi.c ../push_swap/ft_strlen.c ../push_swap/lst_first.c \
		../push_swap/newstack.c ../push_swap/ft_split.c ../push_swap/lst_stack.c \
		../push_swap/error.c

all : $(NAME)

$(NAME) : $(FILE)
	$(CC) $(W) $^ -D BUFFER_SIZE=5 -o $(NAME)
