# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:06:10 by youskim           #+#    #+#              #
#    Updated: 2022/04/05 13:30:08 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
W = -Wall -Wextra -Werror
FILE = push_swap.c lst_first.c lst_stack.c algorithm.c ft_atoi.c newstack.c operation_a.c operation_b.c ft_split.c ft_strlen.c ft_memset.c max_min.c a_to_b.c b_to_a.c sort_algorithm.c

all : $(NAME)

$(NAME) : $(FILE)
	$(CC) $(W) $^ -o $(NAME)
