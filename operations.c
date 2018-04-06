/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:07:13 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 17:58:14 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *a, t_stack *b, char option)
{
	int tmp;

	if ((option == 'a' || option == 's') && a->size > 1)
	{
		tmp = a->nb[a->size - 1];
		a->nb[a->size - 1] = a->nb[a->size - 2];
		a->nb[a->size - 2] = tmp;
	}
	if ((option == 'b' || option == 's') && b->size > 1)
	{
		tmp = b->nb[b->size - 1];
		b->nb[b->size - 1] = b->nb[b->size - 2];
		b->nb[b->size - 2] = tmp;
	}
}

void	op_push(t_stack *a, t_stack *b, char option)
{
	if (option == 'a' && b->size)
	{
		stack_push(a, stack_pop(b));
	}
	else if (option == 'b' && a->size)
	{
		stack_push(b, stack_pop(a));
	}
}

void	op_rotate(t_stack *a, t_stack *b, char option)
{
	int tmp;
	int i;

	if ((option == 'a' || option == 'r') && a->size > 1)
	{
		i = a->size - 1;
		tmp = a->nb[i];
		while (i - 1 >= 0)
		{
			a->nb[i] = a->nb[i - 1];
			i--;
		}
		a->nb[0] = tmp;
	}
	if ((option == 'b' || option == 'r') && b->size > 1)
	{
		i = b->size - 1;
		tmp = b->nb[i];
		while (i - 1 >= 0)
		{
			b->nb[i] = b->nb[i - 1];
			i--;
		}
		b->nb[0] = tmp;
	}
}

void	op_reverse_rotate(t_stack *a, t_stack *b, char option)
{
	int tmp;
	int i;

	i = 1;
	if ((option == 'a' || option == 'r') && a->size > 1)
	{
		tmp = a->nb[0];
		while (i < a->size)
		{
			a->nb[i - 1] = a->nb[i];
			i++;
		}
		a->nb[a->size - 1] = tmp;
	}
	if ((option == 'b' || option == 'r') && b->size > 1)
	{
		tmp = b->nb[0];
		while (i < b->size)
		{
			b->nb[i - 1] = b->nb[i];
			i++;
		}
		b->nb[b->size - 1] = tmp;
	}
}
