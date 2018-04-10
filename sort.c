/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:24:01 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 18:24:02 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three_or_five(t_stack *a, t_stack *b, int number)
{
	if (number == 3)
	{
		while (!content_is_inverse_ordered(a))
		{
			if (a->nb[2] > a->nb[1] && a->nb[2] > a->nb[0])
				instructions_exec(a, b, "ra");
			else
				instructions_exec(a, b, "sa");
		}
	}
	else
	{
		number = subset_median(a->nb, 5, 2);
		while (content_contains_lower(a, number))
			if (stack_peek(a) < number)
				instructions_exec(a, b, "pb");
			else
				instructions_exec(a, b, "ra");
		sort_three_or_five(a, b, 3);
		while (b->size)
			instructions_exec(a, b, "pa");
		if (stack_peek(a) > a->nb[3])
			instructions_exec(a, b, "sa");
	}
}

int			sort_less_than_two_elements_a(t_stack *a, t_stack *b,
											int elements)
{
	if (elements == 1 || elements == 2 || subset_inverse_ordered(a, elements))
	{
		if (elements == 2 && stack_peek(a) > a->nb[a->size - 2])
			instructions_exec(a, b, "sa");
		return (1);
	}
	return (0);
}

int			sort_less_than_two_elements_b(t_stack *a, t_stack *b,
											int elements)
{
	if (elements == 1 || elements == 2 || subset_ordered(b, elements))
	{
		if (elements == 2 && stack_peek(b) < b->nb[b->size - 2])
			instructions_exec(a, b, "sb");
		return (1);
	}
	return (0);
}

void		sort_a(t_stack *a, t_stack *b, int elements, int reorder)
{
	int median;
	int transferts;
	int rotations;

	if (sort_less_than_two_elements_a(a, b, elements))
		return ;
	median = subset_median(a->nb + a->size - elements, elements, elements / 2);
	transferts = 0;
	rotations = 0;
	while (content_contains_lower(a, median))
	{
		transferts += (stack_peek(a) < median);
		rotations += (stack_peek(a) >= median);
		if (stack_peek(a) < median)
			instructions_exec(a, b, "pb");
		else
			instructions_exec(a, b, "ra");
	}
	if (reorder)
		while (rotations--)
			instructions_exec(a, b, "rra");
	sort_a(a, b, a->size, reorder);
	sort_b(a, b, transferts);
}

void		sort_b(t_stack *a, t_stack *b, int elements)
{
	int median;
	int transferts;
	int rotations;

	if (sort_less_than_two_elements_b(a, b, elements))
	{
		subset_flush_b(a, b, elements);
		return ;
	}
	transferts = 0;
	median = subset_median(b->nb + b->size - elements, elements, elements / 2);
	rotations = 0;
	while (content_contains_higher(b, median))
	{
		transferts += (stack_peek(b) > median);
		rotations += (stack_peek(b) <= median);
		if (stack_peek(b) > median)
			instructions_exec(a, b, "pa");
		else
			instructions_exec(a, b, "rb");
	}
	while (rotations--)
		instructions_exec(a, b, "rrb");
	sort_a(a, b, transferts, 1);
	sort_b(a, b, elements - transferts);
}
