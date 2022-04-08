/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_only.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:15:04 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 16:15:11 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_only3arg(t_stack *a)
{
	int	max;
	int	min;

	max_min(a, &max, &min, 3);
	if (a->top->index == max)
	{
		ra(a);
		if (a->top->index != min)
			sa(a);
		return ;
	}
	if (a->top->index == min && a->bottom->index != max)
	{
		rra(a);
		sa(a);
		return ;
	}
	if (a->top->index != max && a->top->index != min)
	{
		if (a->bottom->index == max)
			sa(a);
		else
			rra(a);
		return ;
	}
}

void	sort_only5arg(t_stack *a, t_stack *b)
{
	int	max;
	int	min;
	int	mid;
	int	i;

	max_min(a, &max, &min, 5);
	mid = (max + min) / 2;
	i = 0;
	while (++i < 6)
	{
		if (a->top->index < mid)
			pb(b, a);
		else
			ra(a);
	}
	sort_2arg(a, b, 2);
	sort_only3arg(a);
	pa(a, b);
	pa(a, b);
}

static void	sort_only3arg_b2(t_stack *a, t_stack *b, int max, int min)
{
	if (b->top->index == max && b->bottom->index != min)
	{
		sb(b);
		rb(b);
	}
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_only3arg_b(t_stack *a, t_stack *b)
{
	int	max;
	int	min;

	max_min(b, &max, &min, 3);
	if (b->top->index == min)
	{
		if (b->bottom->index == max)
		{
			sb(b);
			rrb(b);
		}
		else
			rb(b);
	}
	if (b->top->index != min && b->top->index != max)
	{
		if (b->bottom->index == min)
			sb(b);
		else
			rrb(b);
	}
	sort_only3arg_b2(a, b, max, min);
}

void	sort_only5arg_b(t_stack *a, t_stack *b)
{
	int	max;
	int	min;
	int	mid;
	int	i;

	max_min(b, &max, &min, 5);
	mid = (max + min) / 2;
	i = 0;
	while (++i < 6)
	{
		if (b->top->index > mid)
			pa(a, b);
		else
			rb(b);
	}
	sort_2arg(a, b, 2);
	sort_only3arg_b(a, b);
}
