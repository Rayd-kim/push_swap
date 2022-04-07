/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:43:39 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 14:43:41 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_stack(char *str, t_stack *a, int *index)
{
	t_node	*lst;

	lst = (t_node *)malloc(sizeof(t_node));
	if (lst == 0)
		return (NULL);
	a->bottom->prev = lst;
	lst->prev = NULL;
	lst->next = a->bottom;
	lst->value = ft_atoi(str);
	lst->index = *index;
	a->size++;
	*index = *index + 1;
	return (lst);
}
