# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:06:10 by youskim           #+#    #+#              #
#    Updated: 2022/04/09 12:07:10 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
W = -Wall -Wextra -Werror
FILE = main.c push_swap.c operation_a.c operation_b.c operation_ab.c ft_atoi_long.c \
		ft_strlen.c lst_first.c newstack.c ft_split.c lst_stack.c error.c \
		./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c

all : $(NAME)

$(NAME) : $(FILE)
	$(CC) $(W) $^ -o $(NAME)
