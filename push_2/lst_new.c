#include "push_swap.h"

t_node	*lst_new(char *str)
{
	t_node	*start;

	start = (t_node*)malloc(sizeof(t_node));
	if (start == 0)
		return (NULL);
	start->prev = NULL;
	start->next = NULL;
	start->value = ft_atoi(str);
	return (start);
}