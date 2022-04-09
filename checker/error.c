/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:51 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 12:05:01 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_free(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*free_temp;

	temp = a->top;
	while (temp != NULL)
	{
		free_temp = temp;
		temp = temp->prev;
		free(free_temp);
	}
	free(a);
	temp = b->top;
	while (temp != NULL)
	{
		free_temp = temp;
		temp = temp->prev;
		free(free_temp);
	}
	free(b);
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
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
