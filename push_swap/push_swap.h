/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:45:59 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 16:17:28 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
typedef struct s_num_b
{
	int	pa_num;
	int	ra_num;
	int	rb_num;
	int	pivot1;
	int	pivot2;
}		t_num_b;
typedef struct s_num_a
{
	int	pb_num;
	int	ra_num;
	int	rb_num;
	int	pivot1;
	int	pivot2;
}		t_num_a;
t_stack			*newstack(void);
t_node			*lst_first(char *str, int *index);
t_node			*lst_stack(char *str, t_stack *a, int *index);
long long int	ft_atoi(const char *str);
int				push_swap(int argc, char *argv[], t_stack *a);

void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

void			sort_2arg(t_stack *a, t_stack *b, int num);
void			sort_3arg(t_stack *a, t_stack *b, int num);
void			sort_3arg_b(t_stack *a, t_stack *b, int num);
void			sort_4arg(t_stack *a, t_stack *b, int num);
void			sort_4arg_b(t_stack *a, t_stack *b, int num);
void			sort_5arg(t_stack *a, t_stack *b, int num);
void			sort_5arg_b(t_stack *a, t_stack *b, int num);
void			sort_only3arg(t_stack *a);;
void			sort_only5arg(t_stack *a, t_stack *b);
void			sort_only3arg_b(t_stack *a, t_stack *b);
void			sort_only5arg_b(t_stack *a, t_stack *b);

void			a_to_b(t_stack *a, t_stack *b, int num, int *first);
void			b_to_a(t_stack *a, t_stack *b, int num, int *first);
void			max_min(t_stack *stack, int *max, int *min, int num);

void			set_pivot_a(t_stack *a, int num, int *pivot1, int *pivot2);
void			set_pivot_b(t_stack *b, int num, int *pivot1, int *pivot2);
void			rrab(t_stack *a, t_stack *b, t_num_b *numbers, int *first);
void			rr_stack(t_stack *a, t_stack *b, t_num_a *numbers, int *first);

void			*ft_memset(void *b, int c, size_t n);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s1);

void			free_split(char **split);
int				error_check(int argc, char *argv[]);
void			error_free(t_stack *a, t_stack *b);
int				null_check(t_stack *a, t_stack *b);

void			a_to_b_first(t_stack *a, t_stack *b, int num, int *first);
#endif
