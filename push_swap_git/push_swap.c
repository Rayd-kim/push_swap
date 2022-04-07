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

void	error_free(t_stack *a, t_stack *b)
{
	free(a);
	free(b);
}

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

int	null_check(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
	{
		error_free(a, b);
		return (-1);
	}
	return (0);
}

int	check_split(char **split)
{
	int	pm_num;
	int	i;
	int	k;

	if (split[0] == NULL)
		return (-1);
	i = 0;
	while (split[i] != NULL)
	{
		k = 0;
		pm_num = 0;
		while (split[i][k] != '\0')
		{
			if (split[i][k] == '-' || split[i][k] == '+')
				pm_num++;
			k++;
		}
		if (pm_num > 1)
			return (-1);
		i++;
	}
	return (0);
}

int	push_swap(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int			i;
	int			k;
	static int	index = 0;
	char		**split;

	if (error_check(argc, argv) == -1)
		return (-1);
	k = 1;
	while (k < argc)
	{
		split = ft_split(argv[k], ' ');
		if (check_split(split) == -1)
			return (-1);
		i = 0;
		while (split[i] != NULL)
		{
			if (i == 0 && k == 1)
				set_first_stack(split[i], a, &index);
			else
				a->bottom = lst_stack(split[i], a, &index);
			if (a->bottom == NULL)
			{
				error_free (a, b);
				return (-1);
			}
			i++;
		}
		k++;
	}
	return (0);
}
