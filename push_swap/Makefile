# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:06:10 by youskim           #+#    #+#              #
#    Updated: 2022/04/09 13:16:40 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

W = -Wall -Wextra -Werror

FILE = push_swap.c lst_first.c lst_stack.c main.c ft_atoi_long.c newstack.c operation_a.c \
	operation_b.c max_min.c a_to_b_1.c a_to_b_2.c \
	sort_algorithm_a.c sort_algorithm_b.c sort_algorithm_only.c operation_ab.c \
	error.c b_to_a_1.c b_to_a_2.c a_to_b_first.c
	
OBJS = $(FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(W) $(OBJS) -L../libft -lft  -o $(NAME)

$(OBJS) : $(FILE)
	@$(MAKE) -C ../libft all
	$(CC) $(W) -c $(FILE)

bonus :
	@$(MAKE) -C ../checker all

clean :
	rm -rf $(OBJS)
	@$(MAKE) -C ../libft clean
	@$(MAKE) -C ../checker clean

fclean : clean
	rm -rf $(NAME)
	@$(MAKE) -C ../libft fclean
	@$(MAKE) -C ../checker fclean

re : fclean all

.PHONY: all clean fclean re bonus
