#include "push_swap.h"
typedef struct s_num
{
	int	pb_num;
	int	ra_num;
	int	rb_num;
	int	pivot1;
	int	pivot2;
}		t_num;

static void    rr_stack(t_stack *a, t_stack *b, int a_num, int b_num, int *first)
{
	int	same;
	int	temp;

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
	while (b_num - same > 0)
	{
		rrb(b);
		b_num--;
	}
}

void	set_pivot_a(t_stack *a, int num, int *pivot1, int *pivot2)
{
	int	max;
	int	min;

	max_min(a, &max, &min, num);
	*pivot1 = (max + min) / 2;
	*pivot2 = (min + *pivot1) / 2;
}

void	sort_in_range_a(t_stack *a, t_stack *b, int num, t_num *numbers)
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
			if (b->top->index > numbers->pivot2)
			{
				rb(b);
				numbers->rb_num++;
			}
			numbers->pb_num++;
		}
		num--;
	}
}

void	a_to_b(t_stack *a, t_stack *b, int num)
{
	static int	first = 0;
	t_num		*numbers;
	int			temp;
	t_node		*node;

	numbers = (t_num *)malloc(sizeof(t_num));
	if (numbers == 0)
		return ;
	temp = num;
	node = a->top;
	while (temp > 1)
	{
		if (node->index - node->prev->index == -1)
			temp--;
		else
			break ;
		if (temp == 1)
			return ;
		node = node->prev;
	}
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
	if (num == 4)
	{
		sort_4arg(a, b);
		return ;
	}
	if (num == 5)
	{
		sort_5arg(a, b);
		return ;
	}
	/*
	if (num <= 5)
	{
		sort_2arg(a, b);
		sort_3arg(a, b);
		sort_5arg(a, b);
		return ;
	}
	*/
	ft_memset(numbers, 0, sizeof(t_num));
	set_pivot_a(a, num, &numbers->pivot1, &numbers->pivot2);
	sort_in_range_a(a, b, num, numbers);
	rr_stack(a, b, numbers->ra_num, numbers->rb_num, &first);
	a_to_b(a, b, numbers->ra_num);
	b_to_a(a, b, numbers->rb_num, &first);
	b_to_a(a, b, numbers->pb_num - numbers->rb_num, &first);
}
