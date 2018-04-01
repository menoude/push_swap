#include "push_swap.h"

static int	subset_median_value(int *set, int len, int rank)
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
		return (subset_median_value(left, left_size, rank));
	else
		return (subset_median_value(right, right_size, rank - left_size - 1));
}

static void	subset_put_max_up(t_stack *a, t_stack *b, int max)
{
	int		pos;
	char	*instruct;

	pos = 0;
	while (a->nb[pos] != max)
		pos++;
	instruct = a->size - pos - 1 <= a->size / 2 ? "ra" : "rra";
	while (stack_peek(a) != max)
		instructions_exec(a, b, instruct, 'y');
}

static int			subset_is_ordered(t_stack *stack, int start, int len)
{
	int i;

	i = start;
	while (i + 1 < start + len)
	{
		if (stack->nb[i] > stack->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void		subset_sort(t_stack *a, t_stack *b, int start, int len)
{
	int median;
	// int reference_size;
	// int transfers;

	if (subset_is_ordered(a, start, len) || stack_is_ordered(a) || len <= 1)
		return ;
	median = subset_median_value(a->nb + start, len, len / 2);
	ft_printf("subset (from %d to %d) median: %d\n", a->nb[start], a->nb[start + len - 1], median);
	// reference_size = a->size;
	// transfers = 0;
	while (stack_contains_higher(a, median))
	{
		if (stack_peek(a) > median)
		{
			instructions_exec(a, b, "pb", 'n');
			// transfers++;
		}
		else if (stack_peek(a) <= median)
			instructions_exec(a, b, "ra", 'n');
	}
	if (a->size == 2 && a->nb[0] > a->nb[1])
		instructions_exec(a, b, "sa", 'n');
	else
		subset_put_max_up(a, b, median);
	while (b->size)
		instructions_exec(a, b, "pa", 'n');
	if (len)
	{
		subset_sort(a, b, start, len / 2);
		subset_sort(a, b, start + len / 2, len / 2);
	}
}
