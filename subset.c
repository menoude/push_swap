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

int		elements_ordered(t_stack *stack, int elements)
{
	int i;

	i = stack->size - elements;
	while (i + 1 < stack->size)
	{
		if (stack->nb[i] > stack->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		elements_inverse_ordered(t_stack *stack, int elements)
{
	int i;

	i = stack->size - elements;
	while (i + 1 < stack->size)
	{
		if (stack->nb[i] < stack->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void flush_a(t_stack *a, t_stack *b, int elements)
{
	while (elements--)
		instructions_exec(a, b, "pb");
}

void flush_b(t_stack *a, t_stack *b, int elements)
{
	while (elements--)
		instructions_exec(a, b, "pa");
}

void		sort_a(t_stack *a, t_stack *b, int elements)
{
	int median;
	int transferts;
	int rotations;

	if (elements <= 2 || elements_ordered(a, elements))
	{
		if (elements == 2 && stack_peek(a) < a->nb[a->size - 2])
			instructions_exec(a, b, "sa");
		printf("end this set\n");
		return ;
	}
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
	ft_printf("pushed %d elements to b\n", transferts);
	sort_a(a, b, a->size);
	sort_b(a, b, transferts);
}

void		sort_b(t_stack *a, t_stack *b, int elements)
{
	int median;
	int transferts;
	int rotations;

	if (elements <= 2 || elements_inverse_ordered(b, elements))
	{
		if (stack_peek(b) > b->nb[b->size - 2])
			instructions_exec(a, b, "sb");
		flush_b(a, b, elements);
		return ;
	}
	transferts = 0;
	median = stack_median_value(b->nb + b->size - elements, elements, elements / 2);
	printf("%d elements for b, with median = %d\n\n", elements, median);
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
	ft_printf("pushed %d elements to a\n", transferts);
	sort_a(a, b, transferts);
	sort_b(a, b, elements - transferts);
}
