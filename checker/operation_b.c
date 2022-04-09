/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:52 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 11:43:36 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	cheker_sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->top->value;
	b->top->value = b->top->prev->value;
	b->top->prev->value = temp;
	temp = b->top->index;
	b->top->index = b->top->prev->index;
	b->top->prev->index = temp;
}

void	cheker_pb(t_stack *b, t_stack *a)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = a->top;
	if (a->size > 1)
		a->top->prev->next = NULL;
	a->top = a->top->prev;
	if (b->size != 0)
		b->top->next = temp;
	temp->prev = b->top;
	b->top = temp;
	if (b->size == 0)
		b->bottom = b->top;
	b->size++;
	a->size--;
	if (a->size == 0)
		a->bottom = NULL;
}

void	cheker_rb(t_stack *b)
{
	t_node	*temp;

	if (b->size < 2)
		return ;
	temp = b->top;
	b->bottom->prev = b->top;
	b->top->prev->next = NULL;
	b->top->next = b->bottom;
	b->top = b->top->prev;
	temp->prev = NULL;
	b->bottom = temp;
}

void	cheker_rrb(t_stack *b)
{
	t_node	*temp;

	if (b->size < 2)
		return ;
	temp = b->bottom;
	b->bottom->next->prev = NULL;
	b->bottom->prev = b->top;
	b->bottom = b->bottom->next;
	b->top->next = temp;
	temp->next = NULL;
	b->top = temp;
}
