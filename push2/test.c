#include "push_swap.h"
#include <stdio.h>

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

int main(void)
{
    t_stack *a;
    t_stack *b;
    t_node *temp;

    a = (t_stack*)malloc(sizeof(t_stack));
		if (a == 0)
			return (-1);
    a->top = lst_new("12");
    a->bottom = a->top;
    a->size = 1;
    
    a->top = lst_stack("34", a);
    a->top = lst_stack("56", a);
	a->top = lst_stack("78", a);
	a->top = lst_stack("90", a);
    temp = a->bottom;
	printf("prinfa\n");
    for (int i = 0; i < a->size; i++)
    {
        printf ("%d\n", temp->value);
        temp = temp->next;
    }

	/*
	b = (t_stack*)malloc(sizeof(t_stack));
		if (b == 0)
			return (-1);
    b->top = lst_new("78");
    b->bottom = b->top;
    b->size = 1;
    
    b->top = lst_stack("90", b);
    temp = b->bottom;
	printf("printb\n");
    for (int i = 0; i < b->size; i++)
    {
        printf ("%d\n", temp->value);
        temp = temp->next;
    }
    */

	ra(a);
    printf ("change\n \n");
	
    temp = a->bottom;
    printf("prinfa\n");
    for (int i = 0; i < a->size; i++)
    {
        printf ("%d\n", temp->value);
        temp = temp->next;
    }
	/*
	temp = b->bottom;
	printf("printb\n");
    for (int i = 0; i < b->size; i++)
    {
        printf ("%d\n", temp->value);
        temp = temp->next;
    }
	*/
    return 0;
}
