/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:43:31 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 11:51:59 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_first(char *str, int *index)
{
	t_node	*start;

	start = (t_node *)malloc(sizeof(t_node));
	if (start == 0)
		return (NULL);
	start->prev = NULL;
	start->next = NULL;
	start->value = ft_atoi_long(str);
	start->index = *index;
	return (start);
}
