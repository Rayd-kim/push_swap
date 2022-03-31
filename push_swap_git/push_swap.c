#include "push_swap.h"

void	error_free(t_stack *a, t_stack *b)
{
	free(a);
	free(b);
}

void	set_first_stack(char *str, t_stack *stack, int *index)
{
	stack->top = lst_first(str, index);
	stack->bottom = stack->top;
	stack->size = 1;
	*index = *index + 1;
}

int	error_check(int	argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if ((argv[i][k] < '0' || argv[i][k] > '9') && (argv[i][k] != ' '))
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

int	push_swap(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int			i;
	static int	index = 0;
	char	**split;

	split = NULL;
	if (error_check(argc, argv) == -1)
		return (-1);
	if (error_check(argc, argv) == 1)
		return (0);
	i = 0;
	split = ft_split(argv[1], ' ');
	while (split[i] != NULL)
	{
		if (i == 0)
			set_first_stack(split[i], a, &index);
		else
			a->bottom = lst_stack(split[i], a, &index);
		if (a->bottom == NULL)
		{
			error_free(a, b);
			return (-1);
		}
		i++;
	}
	return (0);
}
