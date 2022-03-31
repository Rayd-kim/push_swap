#include "push_swap.h"

void	max_min(t_stack *stack, int *max, int *min, int num)
{
	int	i;
	t_node	*temp;

	i = 1;
	*max = stack->top->index;
	*min = stack->top->index;
	temp = stack->top->prev;
	while (i < num)
	{
		if (*max < temp->index)
			*max = temp->index;
		else if (*min > temp->index)
			*min = temp->index;
		temp = temp->prev;
        i++;
	}
}