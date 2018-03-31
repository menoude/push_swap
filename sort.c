#include "push_swap.h"

static int	sort_find_rank(int *set, int size, int middle, int pivot)
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
		return (sort_find_rank(left, left_size, middle, left[middle]));
	else
		return (sort_find_rank(right, right_size, middle - left_size - 1,
									right[middle - left_size - 1]));
}

void		sort(t_stack *a, t_stack *b, int rank)
{
	int rank_value;
	int i;
	int initial_size;

	if (stack_is_ordered(a))
		return ;
	initial_size = a->size;
	rank_value = sort_find_rank(a->nb, a->size, rank, a->nb[rank]);
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
