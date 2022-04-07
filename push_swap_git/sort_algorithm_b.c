/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:15:44 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 16:15:50 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3arg_b(t_stack *a, t_stack *b, int num)
{
	int	min;
	int	max;

	if (num != 3)
		return ;
	max_min(b, &max, &min, 3);
	if ((b->top->index == min) || b->top->prev->index == max)
		sb(b);
	if (b->top->prev->index == min)
	{
		rb(b);
		sb(b);
		rrb(b);
	}
	if (b->top->prev->index == max)
		sb(b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_4arg_b(t_stack *a, t_stack *b, int num)
{
	int	i;
	int	max;
	int	min;
	int	mid;

	if (num != 4)
		return ;
	max_min(b, &max, &min, 4);
	mid = (max + min) / 2;
	i = 0;
	while (++i < 5)
	{
		if (b->top->index > mid)
			pa(a, b);
		else
			rb(b);
	}
	rrb(b);
	rrb(b);
	sort_2arg(a, b, num - 2);
	pa(a, b);
	pa(a, b);
}

void	sort_5arg_b(t_stack *a, t_stack *b, int num)
{	
	int	i;
	int	max;
	int	min;
	int	mid;

	if (num != 5)
		return ;
	max_min(b, &max, &min, 5);
	mid = (max + min) / 2;
	i = 0;
	while (++i < 6)
	{
		if (b->top->index >= mid)
			pa(a, b);
		else
			rb(b);
	}
	rrb(b);
	rrb(b);
	sort_3arg(a, b, num - 2);
	pa(a, b);
	pa(a, b);
}
