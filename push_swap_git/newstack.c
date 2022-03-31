#include "push_swap.h"

t_stack	*newstack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == 0)
		return (NULL);
	new->size = 0;
	new->top = NULL;
	new->bottom = NULL;
	return (new);
}
