#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
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

int	result_value(const char *str, int index, int sign)
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

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;
	int	pm_num;

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
		return (0);
	result = result_value(str, i, sign);
	return (result);
}

int	check_argv(char *str)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
		check++;
	}
	if (check == 0)
		return (-1);
	return (0);
}

t_node	*lst_new(char *str)
{
	t_node	*start;

	start = (t_node*)malloc(sizeof(t_node));
	if (start == 0)
		return (NULL);
	start->prev = NULL;
	start->next = NULL;
	start->value = ft_atoi(str);
	return (start);
}


t_node	*lst_stack(char *str, t_stack *start)
{
	t_node	*lst;

	lst = (t_node*)malloc(sizeof(t_node));
	if (lst == 0)
		return (NULL);
	start->top->next = lst;
	lst->prev = start->top;
	lst->next = NULL;
	lst->value = ft_atoi(str);
	start->size++;
	return (lst);
}


int main(int argc, char *argv[])
{
	int	i;
	t_stack	*start;

	i = 1;
	if (argc == 1)
		return (-1);
	while (i < argc)
	{
		if (check_argv(argv[i]) == -1)
			return (-1);
		else if (i == 1)
		{
			start = (t_stack*)malloc(sizeof(t_stack));
			if (start == 0)
				return (-1);
			start->top = lst_new(argv[i]);
			start->bottom = start->top;
			start->size = 1;
		}
		else
			start->top = lst_stack(argv[i], start);
		i++;
	}
	return (0);
}
