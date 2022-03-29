#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}		t_stack;
t_stack	*newstack(void);
t_node	*lst_first(char *str, int *index);
t_node	*lst_stack(char *str, t_stack *a, int *index);
int		ft_atoi(const char *str);
int		push_swap(int argc, char *argv[], t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void	sort_3arg(t_stack *a);
void	a_to_b(t_stack *a, t_stack *b, int num);
#endif