/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:49 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 14:45:06 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
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
	write (1, "sa\n", 3);
}

void	pa(t_stack *a, t_stack *b)
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
	write (1, "pa\n", 3);
}

void	ra(t_stack *a)
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
	write (1, "ra\n", 3);
}

void	rra(t_stack *a)
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
	write (1, "rra\n", 4);
}
