/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:56:10 by meyami            #+#    #+#             */
/*   Updated: 2018/04/10 11:56:13 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int i;

	i = a->size > b->size ? a->size - 1 : b->size - 1;
	ft_putendl("   A                     B");
	ft_putendl(" ________             ________");
	while (i >= 0)
	{
		ft_printf("| %5s  |           | %5s  |\n",
							a->size > i ? ft_itoa(a->nb[i]) : " ",
							b->size > i ? ft_itoa(b->nb[i]) : " ");
		i--;
	}
	ft_putendl(" --------             --------");
}
