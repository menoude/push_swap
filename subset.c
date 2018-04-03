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

static void	stack_raise_value(t_stack *a, t_stack *b, int median, char a_or_b)
{
	int rotations;

	rotations = 0;
	if (a_or_b == 'a')
	{
		while (stack_peek(a) != median)
		{
			instructions_exec(a, b, "ra");
			rotations++;
		}
		while (rotations--)
		{
			instructions_exec(a, b, "rra");
			instructions_exec(a, b, "sa");
		}
	}
	if (a_or_b == 'b')
	{
		while (stack_peek(b) != median)
		{
			instructions_exec(a, b, "rb");
			rotations++;
		}
		while (rotations--)
		{
			instructions_exec(a, b, "rrb");
			instructions_exec(a, b, "sb");
		}
	}
}

// static void	stack_push_value_b(t_stack *a, t_stack *b, int median)
// {
// 	int		rotations;
//
// 	rotations = 0;
// 	while (stack_peek(b) != median)
// 	{
// 		ft_printf("-----------------------------median = %d\n", median);
// 		instructions_exec(a, b, "rb");
// 		rotations++;
// 	}
// 	while (rotations--)
// 		instructions_exec(a, b, "rrb");
// }

void		stack_sort_a(t_stack *a, t_stack *b, int elements)
{
	int median;
	int transferts;
	int rotations;

	if (elements <= 2)
		return ;
	median = stack_median_value(a->nb + a->size - elements, elements, elements / 2);
	printf("%d elements for a, with median = %d\n\n", elements, median);
	transferts = 0;
	rotations = 0;
	while (stack_contains_higher(a, median))
	{
		if (stack_peek(a) > median)
		{
			instructions_exec(a, b, "pb");
			transferts++;
		}
		else
		{
			instructions_exec(a, b, "ra");
			rotations++;
		}
	}
	while (rotations--)
		instructions_exec(a, b, "rra");
	stack_raise_value(a, b, median, 'a');
	if (elements == 2 && stack_peek(a) < a->nb[a->size - 2])
		instructions_exec(a, b, "sa");
	if (elements == 1)
		return ;
	ft_printf("pushed %d elements to b\n", transferts);
	stack_sort_a(a, b, a->size);
	stack_sort_b(a, b, transferts);
}

void		stack_sort_b(t_stack *a, t_stack *b, int elements)
{
	int median;
	int transferts;
	int rotations;

	if (elements < 2)
	{
		instructions_exec(a, b, "pa");
		return ;
	}
	median = stack_median_value(b->nb + b->size - elements, elements, elements / 2);
	printf("%d elements for b, with median = %d\n\n", elements, median);
	transferts = 0;
	rotations = 0;
	while (stack_contains_lower(b, median))
	{
		if (stack_peek(b) < median)
		{
			instructions_exec(a, b, "pa");
			transferts++;
		}
		else
		{
			instructions_exec(a, b, "rb");
			rotations++;
		}
	}
	while (rotations--)
		instructions_exec(a, b, "rrb");
	stack_raise_value(a, b, median, 'b');
	if (elements == 2 && stack_peek(a) < a->nb[a->size - 2])
		instructions_exec(a, b, "sb");
	if (elements == 1)
	{
		instructions_exec(a, b, "pa");
		return ;
	}
ft_printf("pushed %d elements to a\n", transferts);
	stack_sort_a(a, b, transferts);
	stack_sort_b(a, b, elements - transferts);
}
