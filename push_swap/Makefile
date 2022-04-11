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

CHECKER = checker

CC = gcc

W = -Wall -Wextra -Werror

FILE = push_swap.c \
		main.c \
		lst_first.c \
		lst_stack.c \
		ft_atoi_long.c \
		newstack.c \
		operation_a.c \
		operation_b.c \
		operation_ab.c \
		max_min.c \
		a_to_b_first.c \
		a_to_b_1.c \
		a_to_b_2.c \
		b_to_a_1.c \
		b_to_a_2.c \
		sort_algorithm_a.c \
		sort_algorithm_b.c \
		sort_algorithm_only.c \
		error.c \

FILE_BONUS = ../checker/main_checker.c \
			push_swap.c \
			../checker/operation_a_checker.c \
			../checker/operation_b_checker.c \
			../checker/operation_ab_checker.c \
			ft_atoi_long.c \
			lst_first.c \
			newstack.c \
			lst_stack.c \
			error.c \
			../checker/get_next_line_utils.c \
			../checker/get_next_line.c

OBJS_B = $(FILE_BONUS:.c=.o)

OBJS = $(FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C ../libft all
	$(CC) $(W) $(OBJS) -L../libft -lft  -o $(NAME)

%.o : %.c
	$(CC) $(W) -c $< -o $@

bonus : $(CHECKER)

$(CHECKER) : $(OBJS_B)
	@$(MAKE) -C ../libft all
	$(CC) $(W) $(OBJS_B) -L../libft -lft -o $(CHECKER)

clean :
	rm -rf $(OBJS)
	@$(MAKE) -C ../libft clean
	rm -rf $(OBJS_B)

fclean : clean
	rm -rf $(NAME)
	@$(MAKE) -C ../libft fclean
	rm -rf $(CHECKER)

re : fclean all

.PHONY: all clean fclean re bonus
