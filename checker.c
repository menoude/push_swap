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
	int verbose;

	verbose = argc > 2 && ft_strequ(argv[1], "-v");
	if (argc < 2)
		error_message();
	else if (argc == 2 || (argc == 3 && verbose))
		args_check_single(&a, &b, argv + verbose);
	else if (argc > 2)
		args_check_multi(&a, &b, argv + verbose);
	instructions_read(&a, &b, verbose);
	if (content_is_inverse_ordered(&a) && !b.size)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}
