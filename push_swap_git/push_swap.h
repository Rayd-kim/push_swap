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
void	sort_2arg(t_stack *a, t_stack *b, int num);
void	sort_5arg(t_stack *a, t_stack *b, int num);
void	sort_3arg(t_stack *a, t_stack *b, int num);
void	sort_3arg_b(t_stack *a, t_stack *b, int num);
void	sort_4arg(t_stack *a, t_stack *b, int num);

void	sort_4arg_b(t_stack *a, t_stack *b, int num);
void	sort_5arg_b(t_stack *a, t_stack *b, int num);
void	sort_only3arg(t_stack *a);;
void	sort_only5arg(t_stack *a, t_stack *b);
void	sort_only3arg_b(t_stack *a, t_stack *b);
void	sort_only5arg_b(t_stack *a, t_stack *b);
void	sort_only6arg(t_stack *a, t_stack *b);
void	sort_only6arg_b(t_stack *a, t_stack *b);
void	sort_6arg(t_stack *a, t_stack *b, int num);
void	sort_6arg_b(t_stack *a, t_stack *b, int num);

void	a_to_b(t_stack *a, t_stack *b, int num);
void	max_min(t_stack *stack, int *max, int *min, int num);
void	b_to_a(t_stack *a, t_stack *b, int num, int *first);
void	*ft_memset(void *b, int c, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

void	a_to_b_first(t_stack *a, t_stack *b, int num);
#endif