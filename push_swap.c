/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:45:35 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:44 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		error_message();
	else if (argc == 2)
		args_check_single(&a, &b, argv);
	else if (argc > 2)
		args_check_multi(&a, &b, argv);
	a.instructions = 0;
	sort_a(&a, &b, a.size, 0);
	clean_instructions(a.instructions);
	instructions_print(a.instructions);
	free(a.nb);
	free(b.nb);
	return (0);
}
