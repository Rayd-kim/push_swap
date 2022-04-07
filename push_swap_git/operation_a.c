#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp;
	temp = a->top->index;
	a->top->index = a->top->prev->index;
	a->top->prev->index = temp;
	write (1, "sa\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size < 2)
	{
		sb(b);
		return ;
	}
	temp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp;
	temp = a->top->index;
	a->top->index = a->top->prev->index;
	a->top->prev->index = temp;
	if (b->size < 2)
	{
		write (1, "sa\n", 3);
		return ;
	}
	temp = b->top->value;
	b->top->value = b->top->prev->value;
	b->top->prev->value = temp;
	temp = b->top->index;
	b->top->index = b->top->prev->index;
	b->top->prev->index = temp;
	write (1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = b->top;
	if (b->size > 1)
		b->top->prev->next = NULL;
	b->top = b->top->prev;
	if (a->size != 0)
		a->top->next = temp;
	temp->prev = a->top;
	a->top = temp;
	if (a->size == 0)
		a->bottom = a->top;
	a->size++;
	b->size--;
	if (b->size == 0)
		b->bottom = NULL;
	write (1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->top;
	a->bottom->prev = a->top;
	a->top->prev->next = NULL;
	a->top->next = a->bottom;
	a->top = a->top->prev;
	temp->prev = NULL;
	a->bottom = temp;
	write (1, "ra\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size < 2)
	{
		rb(b);
		return ;
	}
	temp = a->top;
	a->bottom->prev = a->top;
	a->top->prev->next = NULL;
	a->top->next = a->bottom;
	a->top = a->top->prev;
	temp->prev = NULL;
	a->bottom = temp;
	if (b->size < 2)
	{
		write (1, "ra\n", 3);
		return ;
	}
	temp = b->top;
	b->bottom->prev = b->top;
	b->top->prev->next = NULL;
	b->top->next = b->bottom;
	b->top = b->top->prev;
	temp->prev = NULL;
	b->bottom = temp;
	write (1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->bottom;
	a->bottom->next->prev = NULL;
	a->bottom->prev = a->top;
	a->bottom = a->bottom->next;
	a->top->next = temp;
	temp->next = NULL;
	a->top = temp;
	write (1, "rra\n", 4);
}
