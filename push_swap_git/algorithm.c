/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:43:05 by youskim           #+#    #+#             */
/*   Updated: 2022/04/07 14:43:07 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quicksort2(int *arr, int *i_f, int *i_l)
{
	int	temp;

	temp = arr[*i_l];
	arr[*i_l] = arr[*i_f];
	arr[*i_f] = temp;
	*i_f = *i_f + 1;
	*i_l = *i_l - 1;
}

static void	quicksort(int *arr, int i_f, int i_l)
{
	int	pivot;
	int	left;
	int	right;

	left = i_f;
	right = i_l;
	pivot = arr[(i_f + i_l) / 2];
	while (i_f <= i_l)
	{
		while (arr[i_f] < pivot)
			i_f++;
		while (arr[i_l] > pivot)
			i_l--;
		if (i_f <= i_l)
			quicksort2(arr, &i_f, &i_l);
	}
	if (i_f < right)
		quicksort(arr, i_f, right);
	if (i_l > left)
		quicksort(arr, left, i_l);
}

static void	sort_arr(t_stack *a)
{
	int		*arr;
	t_node	*temp;
	int		i;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (arr == 0)
		return ;
	i = -1;
	temp = a->bottom;
	while (temp != NULL)
	{
		arr[++i] = temp->value;
		temp = temp->next;
	}
	quicksort(arr, 0, a->size - 1);
	temp = a->bottom;
	while (temp != NULL)
	{
		i = 0;
		while (temp->value != arr[i])
			i++;
		temp->index = i;
		temp = temp->next;
	}
	free(arr);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	static int	first = 0;

	if (argc == 1)
		return (0);
	a = newstack();
	b = newstack();
	if (null_check(a, b) == -1)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (push_swap(argc, argv, a) == -1)
	{
		write (1, "Error\n", 6);
		system("leaks push_swap > leaks_result; cat leaks_result | grep leaked; rm -rf leaks_result");
		//error_free(a, b);
		return (0);
	}
	sort_arr(a);
	a_to_b_first(a, b, a->size, &first);
	if (first < 0)
		write (1, "Error\n", 6);
	//error_free(a, b);
	system("leaks push_swap > leaks_result; cat leaks_result | grep leaked; rm -rf leaks_result");
	return (0);
}
