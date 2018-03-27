#include "push_swap.h"

void	numbers_init(t_num *numbers)
{
	numbers->nb_args = 0;
	numbers->numbers = 0;
}

void	numbers_swap(t_num *numbers, int i, int j)
{
	int tmp;

	tmp = numbers->numbers[i];
	numbers->numbers[i] = numbers->numbers[j];
	numbers->numbers[j] = tmp;
}

int		numbers_are_sorted(t_num *numbers)
{
	int i;

	i = 0;
	while (i < numbers->nb_args - 1)
	{
		if (numbers->numbers[i] > numbers->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
