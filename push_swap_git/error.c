/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:51 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 16:35:54 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
