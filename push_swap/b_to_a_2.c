/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:52:45 by youskim           #+#    #+#             */
/*   Updated: 2022/04/10 12:52:48 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot_b(t_stack *b, int num, int *pivot1, int *pivot2)
{
	int	max;
	int	min;

	max_min(b, &max, &min, num);
	*pivot1 = (max + min) / 2;
	*pivot2 = (max + *pivot1) / 2;
}

void	rrab(t_stack *a, t_stack *b, t_num_b *numbers, int *first)
{
	int	ra_temp;
	int	rb_temp;

	ra_temp = numbers->ra_num;
	rb_temp = numbers->rb_num;
	while (rb_temp > 0)
	{
		rrb(b);
		rb_temp--;
	}
	a_to_b(a, b, numbers->pa_num - numbers->ra_num, first);
	while (ra_temp > 0)
	{
		rra(a);
		ra_temp--;
	}
}
