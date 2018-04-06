/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:07:26 by meyami            #+#    #+#             */
/*   Updated: 2018/03/29 15:07:28 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_pop(t_stack *stack)
{
	int nb;

	nb = stack->nb[stack->size - 1];
	stack->size--;
	return (nb);
}

void	stack_push(t_stack *stack, int n)
{
	stack->nb[stack->size] = n;
	stack->size++;
}

int		stack_peek(t_stack *stack)
{
	return (stack->nb[stack->size - 1]);
}

int		stack_contains(t_stack *stack, int n)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int		stack_contains_higher(t_stack *stack, int n)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] > n)
			return (1);
		i++;
	}
	return (0);
}

int		stack_contains_lower(t_stack *stack, int n)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] < n)
			return (1);
		i++;
	}
	return (0);
}

int		stack_is_ordered(t_stack *stack)
{
	int i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->nb[i] > stack->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		stack_is_inverse_ordered(t_stack *stack)
{
	int i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->nb[i] < stack->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	stack_raise_value(t_stack *a, t_stack *b, t_instruct *instructions, int median, char a_or_b)
{
	int rotations;

	rotations = 0;
	if (a_or_b == 'a')
	{
		while (stack_peek(a) != median)
		{
			instructions_exec(a, b, instructions, "ra");
			rotations++;
		}
		while (rotations--)
		{
			instructions_exec(a, b, instructions, "rra");
			instructions_exec(a, b, instructions, "sa");
		}
	}
	if (a_or_b == 'b')
	{
		while (stack_peek(b) != median)
		{
			instructions_exec(a, b, instructions, "rb");
			rotations++;
		}
		while (rotations--)
		{
			instructions_exec(a, b, instructions, "rrb");
			instructions_exec(a, b, instructions, "sb");
		}
	}
}
