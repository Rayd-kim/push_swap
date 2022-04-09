# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:06:10 by youskim           #+#    #+#              #
#    Updated: 2022/04/09 13:18:57 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

W = -Wall -Wextra -Werror

FILE = main.c push_swap.c operation_a.c operation_b.c operation_ab.c ft_atoi_long.c \
		lst_first.c newstack.c lst_stack.c error.c get_next_line_utils.c get_next_line.c
		
OBJS = $(FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(W) $(OBJS) -L../libft -lft -o $(NAME)

$(OBJS) : $(FILE)
	@$(MAKE) -C ../libft all
	$(CC) $(W) -c $(FILE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
