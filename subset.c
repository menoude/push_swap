#include "push_swap.h"

static int	stack_median_value(int *set, int len, int rank)
{
	int left[len - 1];
	int right[len - 1];
	int	left_size;
	int	right_size;
	int i;

	left_size = 0;
	right_size = 0;
	i = 1;
	while (i < len)
	{
		if (set[i] < set[0])
			left[left_size++] = set[i++];
		else if (set[i] > set[0])
			right[right_size++] = set[i++];
	}
	if (left_size == rank)
		return (set[0]);
	else if (left_size > rank)
		return (stack_median_value(left, left_size, rank));
	else
		return (stack_median_value(right, right_size, rank - left_size - 1));
}

static void	stack_raise_median_a(t_stack *a, t_stack *b, int median)
{
	int		pos;
	char	*instruct;

	pos = 0;
	while (a->nb[pos] != median)
		pos++;
	instruct = a->size - pos - 1 <= a->size / 2 ? "ra" : "rra";
	while (stack_peek(a) != median)
		instructions_exec(a, b, instruct, 'y');
}

static void	stack_raise_median_b(t_stack *a, t_stack *b, int median)
{
	int		pos;
	char	*instruct;

	pos = 0;
	while (b->nb[pos] != median)
		pos++;
	instruct = b->size - pos - 1 <= b->size / 2 ? "rb" : "rrb";
	while (stack_peek(b) != median)
		instructions_exec(a, b, instruct, 'y');
}

void		stack_sort_a(t_stack *a, t_stack *b, t_stack *medians)
{
	int median;

	if (a->size == 1)
		return ;
	median = stack_median_value(a->nb, a->size, a->size / 2);
	stack_push(medians, median);
	while (stack_contains_higher(a, median) && a->size > 2)
	{
		if (stack_peek(a) > median)
			instructions_exec(a, b, "pb", 'y');
		else
			instructions_exec(a, b, "ra", 'y');
	}
	stack_raise_median_a(a, b, median);
	if (a->size == 2)
	{
		stack_pop(medians);
		stack_sort_b(a, b, medians);
	}
	else
		stack_sort_a(a, b, medians);
}

void		stack_sort_b(t_stack *a, t_stack *b, t_stack *medians)
{
	int median;

	if (b->size == 1)
	{
		instructions_exec(a, b, "pa", 'y');
		return ;
	}
	else if (b->size == 2)
	{
		if (stack_peek(b) > b->nb[b->size - 2])
			instructions_exec(a, b, "sb", 'y');
		while (b->size)
			instructions_exec(a, b, "pa", 'y');
		return ;
	}
	median = medians->size ? stack_pop(medians)
					: stack_median_value(b->nb, b->size, b->size / 2);
	while (stack_contains_lower(b, median) && b->size > 2)
	{
			if (stack_peek(b) < median)
				instructions_exec(a, b, "pa", 'y');
			else
				instructions_exec(a, b, "rb", 'y');
	}
	stack_raise_median_b(a, b, median);
	stack_sort_b(a, b, medians);
}
