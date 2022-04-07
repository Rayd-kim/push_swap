/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:42 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 16:22:44 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size < 2)
	{
		sb(b);
		return ;
	}
	temp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp;
	temp = a->top->index;
	a->top->index = a->top->prev->index;
	a->top->prev->index = temp;
	if (b->size < 2)
	{
		write (1, "sa\n", 3);
		return ;
	}
	temp = b->top->value;
	b->top->value = b->top->prev->value;
	b->top->prev->value = temp;
	temp = b->top->index;
	b->top->index = b->top->prev->index;
	b->top->prev->index = temp;
	write (1, "ss\n", 3);
}

static int	rrcheck_size(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size >= 2)
	{
		rb(b);
		return (-1);
	}
	else if (a->size >= 2 && b->size < 2)
	{
		ra(a);
		return (-1);
	}
	else if (a->size < 2 && b->size < 2)
		return (-1);
	else
		return (0);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (rrcheck_size(a, b) == -1)
		return ;
	temp = a->top;
	a->bottom->prev = a->top;
	a->top->prev->next = NULL;
	a->top->next = a->bottom;
	a->top = a->top->prev;
	temp->prev = NULL;
	a->bottom = temp;
	temp = b->top;
	b->bottom->prev = b->top;
	b->top->prev->next = NULL;
	b->top->next = b->bottom;
	b->top = b->top->prev;
	temp->prev = NULL;
	b->bottom = temp;
	write (1, "rr\n", 3);
}

static int	rrrcheck_size(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size >= 2)
	{
		rrb(b);
		return (-1);
	}
	else if (a->size >= 2 && b->size < 2)
	{
		rra(a);
		return (-1);
	}
	else if (a->size < 2 && b->size < 2)
		return (-1);
	else
		return (0);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (rrrcheck_size(a, b) == -1)
		return ;
	temp = a->bottom;
	a->bottom->next->prev = NULL;
	a->bottom->prev = a->top;
	a->bottom = a->bottom->next;
	a->top->next = temp;
	temp->next = NULL;
	a->top = temp;
	temp = b->bottom;
	b->bottom->next->prev = NULL;
	b->bottom->prev = b->top;
	b->bottom = b->bottom->next;
	b->top->next = temp;
	temp->next = NULL;
	b->top = temp;
	write (1, "rrr\n", 4);
}
