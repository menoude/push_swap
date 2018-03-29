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

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	error_message_free_args(char **args)
{
	args_free(args);
	write(2, "Error\n", 6);
	exit(0);
}

void	error_message_free_stacks(t_stack *a, t_stack *b)
{
	free(a->nb);
	free(b->nb);
	write(2, "Error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		error_message();
	else if (argc == 2)
		args_check_single(&a, &b, argv);
	else if (argc > 2)
		args_check_multi(&a, &b, argv);
	print_stacks(&a, &b); // A ENLEVER
	instructions_read(&a, &b);
	// print_stacks(&a, &b); // A ENLEVER
	if (stack_is_ordered(&a) && !b.size)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}
