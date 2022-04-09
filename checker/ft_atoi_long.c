/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:43:16 by youskim           #+#    #+#             */
/*   Updated: 2022/04/09 11:55:50 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static long long int	result_value(const char *str, int index, int sign)
{
	unsigned long long int	result;

	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	if (result > 9223372036854775807 && sign == 1)
		return (-1);
	else if (result - 1 > 9223372036854775807 && sign == -1)
		return (0);
	else
		return (result * sign);
}

long long int	ft_atoi_long(const char *str)
{
	int				i;
	int				sign;
	long long int	result;
	int				pm_num;

	i = 0;
	sign = 1;
	pm_num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		pm_num++;
		i++;
	}
	if (pm_num > 1)
		return (2147483648);
	result = result_value(str, i, sign);
	return (result);
}
