# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:06:10 by youskim           #+#    #+#              #
#    Updated: 2022/04/08 17:58:08 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
W = -Wall -Wextra -Werror
FILE = push_swap.c lst_first.c lst_stack.c algorithm.c ft_atoi.c newstack.c operation_a.c \
	operation_b.c ft_split.c ft_strlen.c ft_memset.c max_min.c a_to_b_1.c a_to_b_2.c \
	sort_algorithm_a.c sort_algorithm_b.c sort_algorithm_only.c operation_ab.c \
	error.c b_to_a_1.c b_to_a_2.c a_to_b_first.c

all : $(NAME)

$(NAME) : $(FILE)
	$(CC) $(W) $^ -o $(NAME)
