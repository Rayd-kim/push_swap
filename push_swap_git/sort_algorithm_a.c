/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:14:58 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 16:15:16 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
