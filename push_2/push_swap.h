#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct	s_node
{
	int	value;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int	size;
	t_node	*top;
	t_node	*bottom;
}		t_stack;
t_node	*lst_new(char *str);
t_node	*lst_stack(char *str, t_stack *start);
int		ft_atoi(const char *str);
#endif