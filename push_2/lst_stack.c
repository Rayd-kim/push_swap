#include "push_swap.h"

t_node	*lst_stack(char *str, t_stack *start)
{
	t_node	*lst;

	lst = (t_node*)malloc(sizeof(t_node));
	if (lst == 0)
		return (NULL);
	start->top->next = lst;
	lst->prev = start->top;
	lst->next = NULL;
	lst->value = ft_atoi(str);
	start->size++;
	return (lst);
}