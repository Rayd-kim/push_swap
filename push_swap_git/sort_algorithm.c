#include "push_swap.h"

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

void	sort_3arg_b(t_stack *a, t_stack *b)
{
	int min;
	int max;
	
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

void	sort_3arg(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	max_min(a, &max, &min, 3);
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

void	sort_4arg(t_stack *a, t_stack *b)
{
	int	i;
	int	max;
	int	min;
	int	mid;

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
	sort_2arg(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_5arg(t_stack *a, t_stack *b)
{	
	int	i;
	int	max;
	int	min;
	int	mid;

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
	sort_3arg(a, b);
	pa(a, b);
	pa(a, b);
}
