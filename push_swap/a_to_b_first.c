/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:41:05 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 18:41:06 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_2(t_stack *a, t_stack *b, int *num, t_num_a *numbers)
{	
	if (a->top->index > numbers->pivot1 && \
		b->top->index <= numbers->pivot2 && *num > 1)
	{
		rr(a, b);
		numbers->ra_num++;
		numbers->rb_num++;
		*num = *num - 1;
	}
	else if (b->top->index <= numbers->pivot2)
	{
		rb(b);
		numbers->rb_num++;
	}
}

static void	sort_a(t_stack *a, t_stack *b, int num, t_num_a *numbers)
{	
	while (num > 0)
	{
		if (a->top->index > numbers->pivot1)
		{
			ra(a);
			numbers->ra_num++;
		}
		else
		{
			pb(b, a);
			numbers->pb_num++;
			sort_a_2(a, b, &num, numbers);
		}
		num--;
	}
}

static int	check_conti(t_stack *a, int num)
{
	t_node	*node;
	int		temp;

	temp = num;
	node = a->top;
	while (temp > 1)
	{
		if (node->index - node->prev->index == -1)
			temp--;
		else
			return (0);
		if (temp == 1)
			return (-1);
		node = node->prev;
	}
	return (0);
}

static void	check_num(t_stack *a, t_stack *b, int num)
{
	if (a->size == 3)
	{
		sort_only3arg(a);
		return ;
	}
	if (a->size == 5)
	{
		sort_only5arg(a, b);
		return ;
	}
	sort_2arg(a, b, num);
	sort_3arg(a, b, num);
	sort_4arg(a, b, num);
	sort_5arg(a, b, num);
	return ;
}

void	a_to_b_first(t_stack *a, t_stack *b, int num, int *first)
{
	t_num_a		*numbers;

	if (check_conti(a, num) == -1)
		return ;
	if (num <= 5)
	{
		check_num(a, b, num);
		return ;
	}
	numbers = (t_num_a *)malloc(sizeof(t_num_a));
	if (numbers == 0)
	{
		*first = -1;
		error_free(a, b);
		return ;
	}
	ft_memset(numbers, 0, sizeof(t_num_a));
	set_pivot_a(a, num, &numbers->pivot1, &numbers->pivot2);
	sort_a(a, b, num, numbers);
	a_to_b(a, b, numbers->ra_num, first);
	b_to_a(a, b, numbers->pb_num - numbers->rb_num, first);
	b_to_a(a, b, numbers->rb_num, first);
	free(numbers);
}
