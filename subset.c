/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:48:39 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 17:49:05 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		subset_median_value(int *set, int len, int rank)
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

int		subset_ordered(t_stack *stack, int elements)
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

int		subset_inverse_ordered(t_stack *stack, int elements)
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

void	subset_flush_a(t_stack *a, t_stack *b, int elements)
{
	while (elements--)
		instructions_exec(a, b, "pb");
}

void	subset_flush_b(t_stack *a, t_stack *b, int elements)
{
	while (elements--)
		instructions_exec(a, b, "pa");
}
