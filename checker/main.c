/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:43:05 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 12:48:10 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

static int	check_operation(char *str)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		return (0);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		return (0);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		return (0);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		return (0);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		return (0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		return (0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		return (0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		return (0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		return (0);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		return (0);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		return (0);
	else
		return (-1);
}

static void	do_operation(char *str, t_stack *a, t_stack *b)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		cheker_sa(a);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		cheker_sb(b);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		cheker_ss(a, b);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		cheker_ra(a);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		cheker_rb(b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		cheker_rr(a, b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		cheker_rra(a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		cheker_rrb(b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		cheker_rrr(a, b);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		cheker_pa(a, b);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		cheker_pb(b, a);
}

static int	checker(t_stack *a, t_stack *b)
{
	char	*str;

	str = get_next_line (0);
	while (str != NULL)
	{
		if ((str[0] == 'E' && str[1] == 'r' && str[2] == 'r' && str[3] == 'o' \
			&& str[4] == 'r') || check_operation(str) != 0)
		{
			write (2, "Error\n", 6);
			return (-1);
		}
		do_operation(str, a, b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (0);
}

static void	sort_check(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->top;
	while (temp->prev != NULL)
	{
		if (temp->value >= temp->prev->value || b->top != NULL)
		{
			write (1, "KO\n", 3);
			error_free(a, b);
			return ;
		}
		else
			temp = temp->prev;
	}
	write (1, "OK\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (0);
	a = newstack();
	b = newstack();
	if (null_check(a, b) == -1)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	if (push_swap(argc, argv, a) == -1)
	{
		write (2, "Error\n", 6);
		error_free(a, b);
		return (0);
	}
	if (checker(a, b) == -1)
	{
		error_free(a, b);
		return (0);
	}
	sort_check(a, b);
	return (0);
}
