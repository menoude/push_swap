#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)  // A ENLEVER
{
	int i;

	i = 0;
	ft_printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	while (i < a->size)
	{
		ft_printf("%d ", a->nb[i]);
		i++;
	}
	i = b->size - 1;
	ft_printf("     |      ");
	while (i >= 0)
	{
		ft_printf("%d ", b->nb[i]);
		i--;
	}
	ft_printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	ft_putstr("\n\n");
}

void	print_set(int *set, char *name, int size)
{
	int i;

	ft_printf("set %s of size %d\n", name, size);
	i = 0;
	while (i < size)
	{
		ft_printf("%d, ", set[i]);
		i++;
	}
	ft_putstr("\n\n");
}
