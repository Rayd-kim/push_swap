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
			if (b->top->index <= numbers->pivot1 && a->top->index < numbers->pivot2 && num > 1)
			{
				rr(a, b);
				numbers->ra_num++;
				numbers->rb_num++;
				num--;
			}
			else if (a->top->index < numbers->pivot2)
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

void	b_to_a(t_stack *a, t_stack *b, int num, int *first)
{
	t_num	*numbers;
	t_node	*node;
	int		temp;

	*first = *first + 1;
	numbers = (t_num *)malloc(sizeof(t_num));
	if (numbers == 0)
		return ;
	temp = num;
	node = b->top;
	while (temp > 1)
	{
		if (node->index - node->prev->index == 1)
			temp--;
		else
			break;
		if (temp == 1)
		{
			while (num > 0)
			{
				pa(a, b);
				num--;
			}		
			return ;
		}
		node = node->prev;
	}
	if (num <= 5)
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
	ft_memset(numbers, 0, sizeof(t_num));
	set_pivot_b(b, num, &numbers->pivot1, &numbers->pivot2);
	sort_in_range_b(a, b, num, numbers);
	rrb_stack(b, numbers->rb_num);
	a_to_b(a, b, numbers->pa_num - numbers->ra_num);
	rra_stack(a, numbers->ra_num);
	a_to_b(a, b, numbers->ra_num);
	b_to_a(a, b, numbers->rb_num, first);
}
