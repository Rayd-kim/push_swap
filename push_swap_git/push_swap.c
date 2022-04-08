/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:45:50 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 14:45:52 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_first_stack(char *str, t_stack *stack, int *index)
{
	stack->top = lst_first(str, index);
	stack->bottom = stack->top;
	stack->size = 1;
	*index = *index + 1;
}

int	error_check(int argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] >= '0' && argv[i][k] <= '9')
				k++;
			else if (argv[i][k] == '+' || argv[i][k] == '-' \
				|| argv[i][k] == ' ')
				k++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_maxmin(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		if (ft_atoi(split[i]) > 2147483647 || ft_atoi(split[i]) < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

int	check_split(char **split, t_stack *a)
{
	t_node	*temp;
	int		check;
	int		i;

	if (split[0] == NULL)
		return (-1);
	temp = a->top;
	if (check_maxmin(split) == -1)
		return (-1);
	while (temp != NULL)
	{
		i = 0;
		check = temp->value;
		while (split[i] != NULL)
		{
			if (ft_atoi(split[i]) == check)
				return (-1);
			i++;
		}
		temp = temp->prev;
	}
	return (0);
}

int	push_swap(int argc, char *argv[], t_stack *a)
{
	int			i;
	int			k;
	static int	index = 0;
	char		**split;

	if (error_check(argc, argv) == -1)
		return (-1);
	k = 0;
	while (++k < argc)
	{
		split = ft_split(argv[k], ' ');
		if (check_split(split, a) == -1)
		{
			i = 0;
			while (split[i] != NULL)
			{
				free(split[i]);
				i++;
			}
			free(split);
			return (-1);
		}
		i = -1;
		while (split[++i] != NULL)
		{
			if (i == 0 && k == 1)
				set_first_stack(split[i], a, &index);
			else
				a->bottom = lst_stack(split[i], a, &index);
			if (a->bottom == NULL)
				return (-1);
		}
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (0);
}
