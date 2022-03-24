#include "push_swap.h"

t_node	*lst_stack(char *str, t_stack *a)
{
	t_node	*lst;

	lst = (t_node *)malloc(sizeof(t_node));
	if (lst == 0)
		return (NULL);
	a->top->next = lst;
	lst->prev = a->top;
	lst->next = NULL;
	lst->value = ft_atoi(str);
	a->size++;
	return (lst);
}
