/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:26 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 12:03:42 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
