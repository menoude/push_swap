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

void print_subset_instructions(int transferts)
{
	ft_printf("pushed %d elements to a\n", transferts);
	ft_printf("%d pb\n", counter_pb);
	ft_printf("%d ra\n", counter_ra);
	ft_printf("%d rra\n", counter_rra);
	ft_printf("%d sa\n", counter_sa);
	ft_printf("%d pa\n", counter_pa);
	ft_printf("%d rb\n", counter_rb);
	ft_printf("%d rrb\n", counter_rrb);
	ft_printf("%d sb\n", counter_sb);
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
