/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:26 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 14:44:28 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == 0)
		return (NULL);
	new->size = 0;
	new->top = NULL;
	new->bottom = NULL;
	return (new);
}
