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
# include "../push_swap/push_swap.h"

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

#endif
