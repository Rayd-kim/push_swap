#include "push_swap.h"

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
