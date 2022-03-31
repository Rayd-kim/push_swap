#include "push_swap.h"

void	b_to_a(t_stack *a, t_stack *b, int num);


void	sort_2arg(t_stack *a, t_stack *b)
{
	int	sa_num;
	int	sb_num;

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

void	sort_3arg(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	t_node	*temp;
	int	i;

	i = 0;
	max = a->top->index;
	min = a->top->index;
	temp = a->top->prev;
	while (++i < 3)
	{
		if (max < temp->index)
			max = temp->index;
		else if (min > temp->index)
			min = temp->index;
		temp = temp->prev;
	}
	if ((a->top->index == max) || a->top->prev->index == min)
		sa(a);
	if (a->top->prev->index == max)
	{	
		ra(a);
		sa(a);
		rra(a);
	}
	if (a->top->prev->index == min)
		sort_2arg(a, b);
}

/*
void	sort_2arg_b(t_stack *a, t_stack *b)
{
	if (b->top->index < b->top->prev->index)
	{	
		sb(b);
		pa(a, b);
		pa(a, b);
	}
	else
	{
		pa(a, b);
		pa(a, b);
	}
}
*/
void	sort_5arg(t_stack *a, t_stack *b)
{
	int	i;
	int	max;
	int	min;
	int	mid;
	t_node	*temp;

	i = 0;
	max = a->top->index;
	min = a->top->index;
	temp = a->top->prev;
	while (++i < 5)
	{
		if (max < temp->index)
			max = temp->index;
		else if (min > temp->index)
			min = temp->index;
		temp = temp->prev;
	}
	mid = (max + min) / 2;
	i = 0;
	while (++i < 6)
	{
		if (a->top->index < mid)
			pb(b, a);
		else
			ra(a);
	}
	sort_3arg(a, b);
	sort_2arg(a, b);
	pb(b, a);
	pb(b, a);
}

void	set_pivot_a(t_node *top, int num, int *pivot1, int *pivot2)
{
	t_node	*temp;
	int	i;
	int	max;
	int	min;

	max = top->index;
	min = top->index;
	temp = top->prev;
	i = 1;
	while (i < num)
	{
		if (temp->index > max)
			max = temp->index;
		else if (temp->index < min)
			min = temp->index;
		temp = temp->prev;
		i++;
	}
	*pivot1 = (max + min) / 2;
	*pivot2 = (min + *pivot1) / 2;
}

void	a_to_b(t_stack *a, t_stack *b, int num)
{
	int	ra_num;
	int	pivot1;
	int	pivot2;
	int	pb_num;
	int	rb_num;
	int	rb_temp;
	int	ra_temp = 0;

	if (num <= 1)
		return ;
	if (num == 2)
	{
		sort_2arg(a, b);
		return ;
	}
	if (num == 3)
	{
		sort_3arg(a, b);
		return ;
	}
	/*if (num == 5)
	{
		sort_5arg(a, b);
		return ;
	}*/
	ra_num = 0;
	pb_num = 0;
	rb_num = 0;
	set_pivot_a(a->top, num, &pivot1, &pivot2);
	while (num > 0)
	{
		if (a->top->index > pivot1)
		{
			ra(a);
			ra_num++;
		}
		else
		{
			pb(b, a);
			if (b->top->index > pivot2)
			{
				rb(b);
				rb_num++;
			}
			pb_num++;
		}
		num--;
	}
	rb_temp = rb_num;
	ra_temp = ra_num;
	while (ra_temp > 0)
	{
		rra(a);
		ra_temp--;
	}
	while (rb_temp > 0)
	{
		rrb(b);
		rb_temp--;
	}
	a_to_b(a, b, ra_num);
	b_to_a(a, b, rb_num);
	b_to_a(a, b, pb_num - rb_num);
}

void	set_pivot_b(t_node *top, int num, int *pivot1, int *pivot2)
{
	t_node	*temp;
	int	max;
	int	min;

	max = top->index;
	min = top->index;
	temp = top->prev;
	while (1 < num)
	{
		if (temp->index > max)
			max = temp->index;
		else if (temp->index < min)
			min = temp->index;
		temp = temp->prev;
		num--;
	}
	*pivot1 = (max + min) / 2;
	*pivot2 = (max + *pivot1) / 2;
}

void	b_to_a(t_stack *a, t_stack *b, int num)
{
	int	pivot1;
	int	pivot2;
	int	pa_num;
	int	rb_num;
	int	ra_num;
	int	ra_temp;
	int	rb_temp = 0;
	if (num < 1)
		return ;
	if (num == 1)
	{
		pa(a, b);
		return ;
	}
	pa_num = 0;
	rb_num = 0;
	ra_num = 0;
	set_pivot_b(b->top, num, &pivot1, &pivot2);
	while (num > 0)
	{
		if (b->top->index > pivot1)
		{
			pa(a, b);
			pa_num++;
			if (a->top->index < pivot2)
			{
				ra(a);
				ra_num++;
			}
		}
		else
		{
			rb(b);
			/*
			if (a->top->index < pivot2)
			{
				ra(a);
				ra_num++;
			}
			*/
			rb_num++;
		}
		num--;
	}
	ra_temp = ra_num;
	rb_temp = rb_num;
	while (rb_temp > 0)
	{
		rrb(b);
		rb_temp--;
	}
	a_to_b(a, b, pa_num - ra_num);
	while (ra_temp > 0)
	{
		rra(a);
		ra_temp--;
	}
	a_to_b(a, b, ra_num);
	b_to_a(a, b, rb_num);
}
