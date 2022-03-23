#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->top->value;
	b->top->value = b->top->prev->value;
	b->top->prev->value = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = b->top;
	b->top->prev->next = NULL;
	a->top->next = b->top;
	b->top->prev = a->top;
	b->top = b->top->prev;
	a->top = temp;
	a->size++;
	b->size--;
}

void	pb(t_stack *b, t_stack *a)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = a->top;
	a->top->prev->next = NULL;
	b->top->next = a->top;
	a->top->prev = b->top;
	a->top = a->top->prev;
	b->top = temp;
	b->size++;
	a->size--;
}

void	ra(t_stack *a)
{
	t_node	*temp;

	if (a->size < 1)
		return ;
	temp = a->top;
	a->bottom->prev = a->top;
	a->top->prev->next = NULL;
	a->top->next = a->bottom;
	a->top = a->top->prev;
	temp->prev = NULL;
	a->bottom = temp;
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (b->size < 1)
		return ;
	temp = b->top;
	b->bottom->prev = b->top;
	b->top->prev->next = NULL;
	b->top->next = b->bottom;
	b->top = b->top->prev;
	temp->prev = NULL;
	b->bottom = temp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*temp;

	if (a->size < 1)
		return ;
	temp = a->bottom;
	a->bottom->next->prev = NULL;
	a->bottom->prev = a->top;
	a->bottom = a->bottom->next;
	a->top->next = temp;
	temp->next = NULL;
	a->top = temp;
}

void	rrb(t_stack *b)
{
	t_node	*temp;

	if (b->size < 1)
		return ;
	temp = b->bottom;
	b->bottom->next->prev = NULL;
	b->bottom->prev = b->top;
	b->bottom = b->bottom->next;
	b->top->next = temp;
	temp->next = NULL;
	b->top = temp;
}
