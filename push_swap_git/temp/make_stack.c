
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
