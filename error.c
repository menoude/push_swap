/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:51:23 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 17:51:24 by meyami           ###   ########.fr       */
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
