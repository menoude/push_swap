/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:06:30 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 18:06:32 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		content_contains_higher(t_stack *stack, int n)
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

int		content_contains_lower(t_stack *stack, int n)
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

int		content_contains(t_stack *stack, int n)
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

int		content_is_ordered(t_stack *stack)
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

int		content_is_inverse_ordered(t_stack *stack)
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
