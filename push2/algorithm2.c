#include "push_swap.h"

void	b_to_a(t_stack *a, t_stack *b, int num);

void	sort_3arg(t_stack *a)
{
	int	min;
	int	max;
	t_node	*temp;
	int	i;

	max = -1;
	min = 2147483647;
	i = 0;
	temp = a->top;
	while (i < 3 || temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		if (temp->index < min)
			min = temp->index;
		temp = temp->prev;
		i++;
	}
	if (a->top->index == max && a->top->index - a->top->prev->index == 2)
	{
		rra(a);
		sa(a);
	}
	else if(a->top->index == min && a->top->index - a->top->prev->index == -1)
	{
		ra(a);
		sa(a);
	}
	else if (a->top->index == min && a->top->index - a->top->prev->index == -2)
		ra(a);
	else if ((a->top->index != max && a->top->index != min)	&& a->top->index - a->top->prev->index == -1)
		sa(a);
	else if ((a->top->index != max && a->top->index != min) && a->top->index - a->top->prev->index == 1)
		rra(a);
}

void	sort_2arg(t_stack *a)
{
	t_node	*temp;

	temp = a->top;
	if (temp->index > temp->prev->index)
		sa(a);
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
	//여기서 처음에 num으로 넘어오는 인자는 스택의 크기이다.
	//pivot보다 큰 부분은 b로, 아닌것들은 ra로 밑으로 내려준다.
	//num만큼 다 돌아가면, ra한 것들이 다시 올라와있을 테니, 다시 ra로 내려준다.
	int	ra_num;
	int	pivot1;
	int	pivot2;
	int	pb_num;
	int	rb_num;
	int	rb_temp;
	int	ra_temp = 0;

	if (num <= 1)
		return ;
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
		}
		else
		{
			rb(b);
			if (a->top->index < pivot2)
			{
				ra(a);
				ra_num++;
			}
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
