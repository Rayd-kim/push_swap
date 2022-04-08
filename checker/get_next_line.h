/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:57:29 by youskim           #+#    #+#             */
/*   Updated: 2022/01/11 17:20:58 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../push_swap/push_swap.h"
# define OPEN_MAX 256

char	*str_cut(char *str);
char	*str_join(char *s1, char *s2);
char	*str_cpy(char *s1);
int		ft_strchr(char *str, char c);
char	*get_next_line(int fd);

void	cheker_sa(t_stack *a);
void	cheker_pa(t_stack *a, t_stack *b);
void	cheker_ra(t_stack *a);
void	cheker_rra(t_stack *a);
void	cheker_sb(t_stack *b);
void	cheker_pb(t_stack *b, t_stack *a);
void	cheker_rb(t_stack *b);
void	cheker_rrb(t_stack *b);
void	cheker_ss(t_stack *a, t_stack *b);
void	cheker_rr(t_stack *a, t_stack *b);
void	cheker_rrr(t_stack *a, t_stack *b);
#endif
