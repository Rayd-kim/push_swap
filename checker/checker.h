/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:06:46 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 13:17:45 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

void			cheker_sa(t_stack *a);
void			cheker_pa(t_stack *a, t_stack *b);
void			cheker_ra(t_stack *a);
void			cheker_rra(t_stack *a);
void			cheker_sb(t_stack *b);
void			cheker_pb(t_stack *b, t_stack *a);
void			cheker_rb(t_stack *b);
void			cheker_rrb(t_stack *b);
void			cheker_ss(t_stack *a, t_stack *b);
void			cheker_rr(t_stack *a, t_stack *b);
void			cheker_rrr(t_stack *a, t_stack *b);

long long int	ft_atoi_long(const char *str);

t_node			*lst_first(char *str, int *index);
t_stack			*newstack(void);
t_node			*lst_stack(char *str, t_stack *a, int *index);

int				push_swap(int argc, char *argv[], t_stack *a);
int				error_check(int argc, char *argv[]);
void			free_split(char **split);
int				null_check(t_stack *a, t_stack *b);
void			error_free(t_stack *a, t_stack *b);

#endif
