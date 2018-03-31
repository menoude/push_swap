#include "push_swap.h"

static int	sort_find_median(int *set, int start, int end, int median_pos,
														int pivot)
{
	int	left[size];
	int	right[size];
	int left_size;
	int right_size;
	int i;

	left_size = 0;
	right_size = 0;
	i = start;
	while (start <= end)
	{
		if (set[start] < pivot)
			left[left_size++] = set[start];
		else if (set[start] > pivot)
			right[right_size++] = set[start];
		start++;
	}
	if (left_size == median_pos)
		return (pivot);
	else if (left_size > median_pos)
		return (sort_find_rank(left, left_size, median_pos, left[median_pos]));
	else
		return (sort_find_rank(right, right_size, middle - left_size - 1,
									right[middle - left_size - 1]));
}

void		sort(t_stack *a, t_stack *b, int start, int end)
{
	int rank_value;
	int i;
	int initial_size;

	if (stack_is_ordered(a) || end - start <= 0)
		return ;
	initial_size = end - start;
	rank_value = sort_find_median(a->nb, start, end, (start + end) / 2, a->nb[end]);
	ft_printf("--------------------\n value at rank %d is %d, the group contains %d elements\n--------------\n", rank, rank_value, initial_size);
	i = 0;
	while (i < initial_size)
	{
		if (stack_peek(a) > rank_value)
			instructions_exec(a, b, "pb", 'y');
		else
			instructions_exec(a, b, "ra", 'y');
		i++;
	}
	while (b->size)
		instructions_exec(a, b, "pa", 'y');
}
