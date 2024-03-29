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
