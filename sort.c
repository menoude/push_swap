#include "push_swap.h"

static int	sort_find_median(int *set, int size, int middle, int pivot)
{
	int	left[size];
	int	right[size];
	int left_size;
	int right_size;
	int i;

	left_size = 0;
	right_size = 0;
	i = 0;
	while (i < size)
	{
		if (set[i] < pivot)
			left[left_size++] = set[i];
		else if (set[i] > pivot)
			right[right_size++] = set[i];
		i++;
	}
	if (left_size == middle)
		return (pivot);
	else if (left_size > middle)
		return (sort_find_median(left, left_size, middle, left[middle]));
	else
		return (sort_find_median(right, right_size, middle - left_size - 1,
									right[middle - left_size - 1]));
}

void		sort_start(t_stack *a, t_stack *b)
{
	int median;

	median = sort_find_median(a->nb, a->size, a->size / 2, a->nb[a->size / 2]);
	ft_printf("median = %d\n", median);
	// instructions_exec(a, b, "pb", 'y');
	(void)b;
}
