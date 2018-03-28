#include "push_swap.h"




void print_stacks(t_stack *a, t_stack *b)  // A ENLEVER
{
	int i;

	i = a->size - 1;
	ft_printf("stack a of size %d\n", a->size);
	while (i >= 0)
	{
		ft_printf("%d\n", a->nb[i]);
		i--;
	}
	i = b->size - 1;
	ft_printf("stack b of size %d\n", b->size);
	while (i >= 0)
	{
		ft_printf("%d\n", b->nb[i]);
		i--;
	}
}



void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	error_message_free_args(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	write(2, "Error\n", 6);
	exit(0);
}

void	error_message_free_stacks(t_stack *a, t_stack *b)
{
	free(a->nb);
	free(b->nb);
	write(2, "Error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		error_message();
	else if (argc == 2)
		args_check_single(&a, argv);
	else if (argc > 2)
		args_check_multi(&a, argv);
	stack_init(&b, a.size);
	instructions_read(&a, &b);
	print_stacks(&a, &b); // A ENLEVER
	if (stack_is_ordered(&a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}
