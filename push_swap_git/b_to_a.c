#include "push_swap.h"

typedef struct s_num
{
	int	pa_num;
	int	ra_num;
	int	rb_num;
	int	pivot1;
	int	pivot2;
}		t_num;

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

void	sort_in_range_b(t_stack *a, t_stack *b, int num, t_num *numbers)
{
	while (num > 0)
	{
		if (b->top->index > numbers->pivot1)
		{
			pa(a, b);
			numbers->pa_num++;
			if (a->top->index < numbers->pivot2)
			{
				ra(a);
				numbers->ra_num++;
			}
		}
		else
		{
			rb(b);
			numbers->rb_num++;
		}
		num--;
	}
}

void	b_to_a(t_stack *a, t_stack *b, int num)
{
	t_num	*numbers;

	numbers = (t_num *)malloc(sizeof(t_num));
	if (numbers == 0)
		return ;
	if (num < 1)
		return ;
	if (num == 1)
	{
		pa(a, b);
		return ;
	}
	if (num == 2)
	{
		sort_2arg(a, b);
		pa(a, b);
		pa(a, b);
		return ;
	}
	if (num == 3)
	{
		sort_3arg_b(a, b);
		return ;
	}
	ft_memset(numbers, 0, sizeof(t_num));
	set_pivot_b(b, num, &numbers->pivot1, &numbers->pivot2);
	sort_in_range_b(a, b, num, numbers);
	rrb_stack(b, numbers->rb_num);
	a_to_b(a, b, numbers->pa_num - numbers->ra_num);
	rra_stack(a, numbers->ra_num);
	a_to_b(a, b, numbers->ra_num);
	b_to_a(a, b, numbers->rb_num);
}
