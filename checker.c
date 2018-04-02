/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:36:15 by meyami            #+#    #+#             */
/*   Updated: 2018/03/29 15:36:17 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	medians;

	if (argc < 2)
		error_message();
	else if (argc == 2)
		args_check_single(&a, &b, argv, &medians);
	else if (argc > 2)
		args_check_multi(&a, &b, argv, &medians);
	// print_stacks(&a, &b); // A ENLEVER
	instructions_read(&a, &b);
	// print_stacks(&a, &b); // A ENLEVER
	if (stack_is_ordered(&a) && !b.size)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}
