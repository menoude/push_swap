#include "push_swap.h"

void	sort_raise_value(t_stack *a, t_stack *b, int median, char a_or_b)
{
	int		rotations;
	t_stack *stack;
	char	*instruction_a;
	char	*instruction_b;
	char	*instruction_c;

	rotations = 0;
	stack = a_or_b == 'a' ? a : b;
	instruction_a = a_or_b == 'a' ? "ra" : "rb";
	instruction_b = a_or_b == 'a' ? "rra" : "rrb";
	instruction_c = a_or_b == 'a' ? "sa" : "sb";
	while (stack_peek(stack) != median)
	{
		instructions_exec(a, b, instruction_a);
		rotations++;
	}
	while (rotations--)
	{
		instructions_exec(a, b, instruction_b);
		instructions_exec(a, b, instruction_c);
	}
}

void		sort_a(t_stack *a, t_stack *b, int elements, int reorder)
{
	int median;
	int transferts;
	int rotations;

	if (elements <= 2 || subset_inverse_ordered(a, elements))
	{
		if (elements == 2 && stack_peek(a) > a->nb[a->size - 2])
			instructions_exec(a, b,  "sa");
		return ;
	}
	median = subset_median_value(a->nb + a->size - elements, elements, elements / 2);
	transferts = 0;
	rotations = 0;
	while (content_contains_lower(a, median))
	{
		transferts += (stack_peek(a) < median);
		rotations += (stack_peek(a) >= median);
		if (stack_peek(a) < median)
			instructions_exec(a, b,  "pb");
		else
			instructions_exec(a, b,  "ra");
	}
	if (!reorder)
		while (rotations--)
			instructions_exec(a, b,  "rra");
	sort_raise_value(a, b, median, 'a');
	sort_a(a, b, a->size, reorder);
	sort_b(a, b, transferts);
}

void		sort_b(t_stack *a, t_stack *b, int elements)
{
	int median;
	int transferts;
	int rotations;

	if (elements <= 2 || subset_ordered(b, elements))
	{
		if (stack_peek(b) < b->nb[b->size - 2])
			instructions_exec(a, b,  "sb");
		subset_flush_b(a, b, elements);
		return ;
	}
	transferts = 0;
	median = subset_median_value(b->nb + b->size - elements, elements, elements / 2);
	rotations = 0;
	while (content_contains_higher(b, median))
	{
		transferts += (stack_peek(b) > median);
		rotations += (stack_peek(b) <= median);
		if (stack_peek(b) > median)
			instructions_exec(a, b,  "pa");
		else
			instructions_exec(a, b,  "rb");
	}
	while (rotations--)
		instructions_exec(a, b,  "rrb");
	sort_raise_value(a, b, median, 'b');
	sort_a(a, b, transferts, 0);
	sort_b(a, b, elements - transferts);
}
