/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:26:59 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 18:27:08 by youskim          ###   ########.fr       */
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

void	rra_stack(t_stack *a, int ra_num)
{
	while (ra_num > 0)
	{
		rra(a);
		ra_num--;
	}
}

void	rrb_stack(t_stack *b, int rb_num)
{
	while (rb_num > 0)
	{
		rrb(b);
		rb_num--;
	}
}
