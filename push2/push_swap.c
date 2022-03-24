#include "push_swap.h"

void	error_free(t_stack *a, t_stack *b)
{
	free(a);
	free(b);
}

void	set_first_stack(char *str, t_stack *stack)
{
	stack->top = lst_first(str);
	stack->bottom = stack->top;
	stack->size = 1;
}

int	error_check(int	argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	if (argc == 1)
		return (-1);
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
				return (-1);
			k++;
		}
		i++;
	}
	return (0);
}

int	null_check(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
	{
		error_free(a, b);
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	if (error_check(argc, argv) == -1)
		return (-1);
	a = newstack();
	b = newstack();
	if (null_check(a, b) == -1)
		return (-1);
	while (i < argc)
	{
		if (i == 1)
			set_first_stack(argv[i], a);
		else
			a->top = lst_stack(argv[i], a);
		if (a->top == NULL)
		{
			error_free(a, b);
			return (-1);
		}
		i++;
	}
	return (0);
}
