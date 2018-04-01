#include "push_swap.h"

static int	subset_median_value(int *set, int start, int len, int rank)
{
	int left[len - 1];
	int right[len - 1];
	int	left_size;
	int	right_size;
	int i;

	if (len <= 1)
		return (set[start]);
	left_size = 0;
	right_size = 0;
	i = start + 1;
	while (i < len)
	{
		if (set[i] < set[start])
			left[left_size++] = set[i++];
		else if (set[i] > set[start])
			right[right_size++] = set[i++];
	}
	if (left_size == rank)
		return (set[0]);
	else if (left_size > rank)
		return (subset_median_value(left, 0, left_size, rank));
	else
		return (subset_median_value(right, 0, right_size, rank - left_size - 1));
}

void		subset_sort(t_stack *a, t_stack *b, int start, int len)
{
	int median;
	int i;

	if (stack_is_ordered(a) || len <= 1)
		return ;
	median = subset_median_value(a->nb, start, len, len / 2 - 1);
	ft_printf("subset values: \n");
	for (int j = start; j < len; j++)
		ft_printf("%d\n", a->nb[j]);
	ft_printf("subset of size %d with median value = %d\n", len, median);
	i = 0;
	while (i < a->size + b->size)
	{
		if (stack_peek(a) <= median)
			instructions_exec(a, b, "ra", 'y');
		else if (stack_peek(a) > median)
			instructions_exec(a, b, "pb", 'y');
		// if (a->size == 2)
		// 	instructions_exec(a, b, "sa", 'y');
		// else if (stack_peek(a) == median)
		// 	instructions_exec(a, b, "sa", 'y');
		i++;
	}
	while (b->size)
		instructions_exec(a, b, "pa", 'y');
	// ft_printf("then we'll sort ", );
	if (len > 1)
	{
		subset_sort(a, b, start, len / 2);
		subset_sort(a, b, start + len / 2, len / 2);
	}
	(void)start;
 	(void)b;
}
