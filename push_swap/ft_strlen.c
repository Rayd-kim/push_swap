/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:22:33 by youskim           #+#    #+#             */
/*   Updated: 2021/11/29 18:45:14 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s1)
{
	int	length;

	if (s1 == NULL)
		return (0);
	length = 0;
	while (s1[length] != '\0')
		length++;
	return (length);
}
