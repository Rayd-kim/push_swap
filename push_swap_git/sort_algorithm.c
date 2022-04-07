/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:58 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 14:45:02 by youskim          ###   ########.fr       */
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
	if (b->top->index == max && b->bottom->index != min)
	{
		sb(b);
		rb(b);
	}
	pa(a, b);
	pa(a, b);
	pa(a, b);
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

void	sort_2arg(t_stack *a, t_stack *b, int num)
{
	int	sa_num;
	int	sb_num;

	if (num != 2)
		return ;
	sa_num = 0;
	sb_num = 0;
	if (a->size >= 2 && (a->top->index > a->top->prev->index))
		sa_num++;
	if (b->size >= 2 && (b->top->index < b->top->prev->index))
		sb_num++;
	if (sa_num > 0 && sb_num > 0)
		ss(a, b);
	else if (sa_num > 0 && sb_num == 0)
		sa(a);
	else if (sa_num == 0 && sb_num > 0)
		sb(b);
}

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

void	sort_3arg(t_stack *a, t_stack *b, int num)
{
	int	min;
	int	max;

	if (num != 3)
		return ;
	max_min(a, &max, &min, 3);
	if ((a->top->index == max) || a->top->prev->index == min)
		sa(a);
	if (a->top->prev->index == max)
	{	
		ra(a);
		sa(a);
		rra(a);
	}
	sort_2arg(a, b, num - 1);
}

void	sort_4arg(t_stack *a, t_stack *b, int num)
{
	int	i;
	int	max;
	int	min;
	int	mid;

	if (num != 4)
		return ;
	max_min(a, &max, &min, 4);
	mid = (max + min) / 2;
	i = 0;
	while (++i < 5)
	{
		if (a->top->index <= mid)
			pb(b, a);
		else
			ra(a);
	}
	rra(a);
	rra(a);
	sort_2arg(a, b, num - 2);
	pa(a, b);
	pa(a, b);
}

void	sort_5arg(t_stack *a, t_stack *b, int num)
{	
	int	i;
	int	max;
	int	min;
	int	mid;

	if (num != 5)
		return ;
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
	rra(a);
	rra(a);
	rra(a);
	sort_3arg(a, b, num - 2);
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
