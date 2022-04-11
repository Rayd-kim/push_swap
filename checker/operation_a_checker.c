/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:31:27 by youskim           #+#    #+#             */
/*   Updated: 2022/04/11 14:31:29 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	cheker_sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp;
	temp = a->top->index;
	a->top->index = a->top->prev->index;
	a->top->prev->index = temp;
}

void	cheker_pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = b->top;
	if (b->size > 1)
		b->top->prev->next = NULL;
	b->top = b->top->prev;
	if (a->size != 0)
		a->top->next = temp;
	temp->prev = a->top;
	a->top = temp;
	if (a->size == 0)
		a->bottom = a->top;
	a->size++;
	b->size--;
	if (b->size == 0)
		b->bottom = NULL;
}

void	cheker_ra(t_stack *a)
{
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->top;
	a->bottom->prev = a->top;
	a->top->prev->next = NULL;
	a->top->next = a->bottom;
	a->top = a->top->prev;
	temp->prev = NULL;
	a->bottom = temp;
}

void	cheker_rra(t_stack *a)
{
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->bottom;
	a->bottom->next->prev = NULL;
	a->bottom->prev = a->top;
	a->bottom = a->bottom->next;
	a->top->next = temp;
	temp->next = NULL;
	a->top = temp;
}
