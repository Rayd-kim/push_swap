/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:08:57 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 19:08:59 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_stack2(t_stack *b, int b_num, int same)
{
	while (b_num - same > 0)
	{
		rrb(b);
		b_num--;
	}
}

void	rr_stack(t_stack *a, t_stack *b, t_num_a *numbers, int *first)
{
	int	same;
	int	temp;
	int	a_num;
	int	b_num;

	a_num = numbers->ra_num;
	b_num = numbers->rb_num;
	same = 0;
	if (a_num > b_num && *first != 0)
		same = b_num;
	else if (a_num <= b_num && *first != 0)
		same = a_num;
	temp = same;
	while (temp > 0 && *first != 0)
	{
		rrr(a, b);
		temp--;
	}
	while (a_num - same > 0 && *first != 0)
	{
		rra(a);
		a_num--;
	}
	rr_stack2(b, b_num, same);
}

void	set_pivot_a(t_stack *a, int num, int *pivot1, int *pivot2)
{
	int	max;
	int	min;

	max_min(a, &max, &min, num);
	*pivot1 = (max + min) / 2;
	*pivot2 = (min + *pivot1) / 2;
}
