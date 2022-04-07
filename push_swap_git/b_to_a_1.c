/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:09:11 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 19:09:14 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_range_b2(t_stack*a, t_stack *b, int *num, t_num_b *numbers)
{
	if (b->top->index <= numbers->pivot1 && \
	a->top->index < numbers->pivot2 && *num > 1)
	{
		rr(a, b);
		numbers->ra_num++;
		numbers->rb_num++;
		*num = *num - 1;
	}
	else if (a->top->index < numbers->pivot2)
	{
		ra(a);
		numbers->ra_num++;
	}
}

static void	sort_in_range_b(t_stack *a, t_stack *b, int num, t_num_b *numbers)
{
	while (num > 0)
	{
		if (b->top->index > numbers->pivot1)
		{
			pa(a, b);
			numbers->pa_num++;
			sort_in_range_b2(a, b, &num, numbers);
		}
		else
		{
			rb(b);
			numbers->rb_num++;
		}
		num--;
	}
}

static void	check_num(t_stack *a, t_stack *b, int num)
{
	if (num == 1)
		pa(a, b);
	else if (num == 2)
	{
		sort_2arg(a, b, num);
		pa(a, b);
		pa(a, b);
	}
	else if (num == 3 && b->size == 3)
		sort_only3arg_b(a, b);
	else if (num == 3)
		sort_3arg_b(a, b, num);
	else if (num == 4)
		sort_4arg_b(a, b, num);
	else if (num == 5 && b->size == 5)
		sort_only5arg_b(a, b);
	else if (num == 5)
		sort_5arg_b(a, b, num);
	return ;
}

static int	check_conti(t_stack *a, t_stack *b, int num)
{
	t_node	*node;
	int		temp;

	temp = num;
	node = b->top;
	while (temp > 1)
	{
		if (node->index - node->prev->index == 1)
			temp--;
		else
			return (0);
		if (temp == 1)
		{
			while (num > 0)
			{
				pa(a, b);
				num--;
			}		
			return (-1);
		}
		node = node->prev;
	}
	return (0);
}

void	b_to_a(t_stack *a, t_stack *b, int num, int *first)
{
	t_num_b	*numbers;

	*first = *first + 1;
	numbers = (t_num_b *)malloc(sizeof(t_num_b));
	if (numbers == 0)
		return ;
	if (check_conti(a, b, num) == -1)
		return ;
	if (num <= 5)
	{
		check_num(a, b, num);
		return ;
	}
	ft_memset(numbers, 0, sizeof(t_num_b));
	set_pivot_b(b, num, &numbers->pivot1, &numbers->pivot2);
	sort_in_range_b(a, b, num, numbers);
	rrb_stack(b, numbers->rb_num);
	a_to_b(a, b, numbers->pa_num - numbers->ra_num, first);
	rra_stack(a, numbers->ra_num);
	a_to_b(a, b, numbers->ra_num, first);
	b_to_a(a, b, numbers->rb_num, first);
}
