#include "push_swap.h"

void		sort_a(t_stack *a, t_stack *b, int elements, t_instruct **instructions)
{
	int median;
	int transferts;
	int rotations;

	if (elements <= 2 || subset_inverse_ordered(a, elements))
	{
		if (elements == 2 && stack_peek(a) > a->nb[a->size - 2])
			instructions_exec(a, b, instructions,  "sa");
		return ;
	}
	median = subset_median_value(a->nb + a->size - elements, elements, elements / 2);
	transferts = 0;
	rotations = 0;
	while (stack_contains_lower(a, median))
	{
		if (stack_peek(a) < median)
		{
			instructions_exec(a, b, instructions,  "pb");
			transferts++;
		}
		else
		{
			instructions_exec(a, b, instructions,  "ra");
			rotations++;
		}
	}
	while (rotations--)
		instructions_exec(a, b, instructions,  "rra");
	stack_raise_value(a, b, *instructions, median, 'a');
	sort_a(a, b, a->size, instructions);
	sort_b(a, b, transferts, instructions);
}

void		sort_b(t_stack *a, t_stack *b, int elements, t_instruct **instructions)
{
	int median;
	int transferts;
	int rotations;

	if (elements <= 2 || subset_ordered(b, elements))
	{
		if (stack_peek(b) < b->nb[b->size - 2])
			instructions_exec(a, b, instructions,  "sb");
		subset_flush_b(a, b, *instructions, elements);
		return ;
	}
	transferts = 0;
	median = subset_median_value(b->nb + b->size - elements, elements, elements / 2);
	rotations = 0;
	while (stack_contains_higher(b, median))
	{
		if (stack_peek(b) > median)
		{
			instructions_exec(a, b, instructions,  "pa");
			transferts++;
		}
		else
		{
			instructions_exec(a, b, instructions,  "rb");
			rotations++;
		}
	}
	while (rotations--)
		instructions_exec(a, b, instructions,  "rrb");
	stack_raise_value(a, b, *instructions, median, 'b');
	sort_a(a, b, transferts, instructions);
	sort_b(a, b, elements - transferts, instructions);
}
