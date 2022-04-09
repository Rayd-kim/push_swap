/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:45:50 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 11:58:11 by youskim          ###   ########.fr       */
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

int	check_maxmin(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		if (ft_atoi_long(split[i]) > 2147483647 || \
			ft_atoi_long(split[i]) < -2147483648)
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
			if (ft_atoi_long(split[i]) == check)
				return (-1);
			i++;
		}
		temp = temp->prev;
	}
	return (0);
}

int	split_to_stack(t_stack *a, int *index, char **split, int k)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		if (i == 0 && k == 1)
			set_first_stack(split[i], a, index);
		else
			a->bottom = lst_stack(split[i], a, index);
		if (a->bottom == NULL)
			return (-1);
		i++;
	}
	return (0);
}

int	push_swap(int argc, char *argv[], t_stack *a)
{
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
			free_split(split);
			return (-1);
		}
		if (split_to_stack(a, &index, split, k) == -1)
			return (-1);
		free_split(split);
	}
	return (0);
}
