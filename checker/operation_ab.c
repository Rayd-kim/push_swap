/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:42 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 11:43:32 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	cheker_ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size < 2)
	{
		cheker_sb(b);
		return ;
	}
	temp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp;
	temp = a->top->index;
	a->top->index = a->top->prev->index;
	a->top->prev->index = temp;
	if (b->size < 2)
		return ;
	temp = b->top->value;
	b->top->value = b->top->prev->value;
	b->top->prev->value = temp;
	temp = b->top->index;
	b->top->index = b->top->prev->index;
	b->top->prev->index = temp;
}

static int	rrcheck_size(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size >= 2)
	{
		cheker_rb(b);
		return (-1);
	}
	else if (a->size >= 2 && b->size < 2)
	{
		cheker_ra(a);
		return (-1);
	}
	else if (a->size < 2 && b->size < 2)
		return (-1);
	else
		return (0);
}

void	cheker_rr(t_stack *a, t_stack *b)
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
}

static int	rrrcheck_size(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size >= 2)
	{
		cheker_rrb(b);
		return (-1);
	}
	else if (a->size >= 2 && b->size < 2)
	{
		cheker_rra(a);
		return (-1);
	}
	else if (a->size < 2 && b->size < 2)
		return (-1);
	else
		return (0);
}

void	cheker_rrr(t_stack *a, t_stack *b)
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
}
