# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:06:10 by youskim           #+#    #+#              #
#    Updated: 2022/04/09 12:22:13 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
W = -Wall -Wextra -Werror
FILE = push_swap.c lst_first.c lst_stack.c main.c ft_atoi_long.c newstack.c operation_a.c \
	operation_b.c ft_split.c ft_strlen.c ft_memset.c max_min.c a_to_b_1.c a_to_b_2.c \
	sort_algorithm_a.c sort_algorithm_b.c sort_algorithm_only.c operation_ab.c \
	error.c b_to_a_1.c b_to_a_2.c a_to_b_first.c
OBJS = $(FILE:.c=.o)

all : $(NAME)

$(OBJS) : $(FILE)
	$(CC) $(W) -c $(FILE)

$(NAME) : $(FILE)
	@$(MAKE) -C ./libft all
	$(CC) $(W) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)
	@$(MAKE) -C ./libft clean

fclean : clean
	rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean

re : fclean all

.PHONY: all clean fclean re
