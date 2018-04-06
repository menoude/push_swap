/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:07:51 by meyami            #+#    #+#             */
/*   Updated: 2018/03/29 15:11:49 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			args_free(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void			args_init_stacks(t_stack *a, t_stack *b,
								char **args, int to_free)
{
	b->memory = a->memory;
	if (!(a->nb = ft_memalloc(sizeof(int) * a->memory)))
	{
		if (to_free)
			error_message_free_args(args);
	}
	else if (!(b->nb = ft_memalloc(sizeof(int) * b->memory)))
	{
		if (to_free)
			error_message_free_args(args);
		free(a->nb);
	}
	a->size = 0;
	b->size = 0;
}

static void		args_finalize(t_stack *a, t_stack *b, char **args,
														int to_free)
{
	int next_nb;
	int i;

	args_init_stacks(a, b, args, to_free);
	i = a->memory;
	while (--i >= 0)
	{
		next_nb = ft_atoi(args[i]);
		if (content_contains(a, next_nb))
		{
			free(a->nb);
			if (to_free)
				args_free(args);
			error_message();
		}
		stack_push(a, next_nb);
	}
	if (to_free)
		args_free(args);
}

void			args_check_single(t_stack *a, t_stack *b, char **argv)
{
	char		**tab;
	int			i;
	long int	n;

	if (!(tab = ft_strsplit(argv[1], ' ')))
		error_message();
	a->memory = 0;
	while (tab[a->memory])
	{
		i = 0;
		while (tab[a->memory][i])
		{
			if (!ft_isdigit(tab[a->memory][i])
				&& !(i == 0 && tab[a->memory][i] == '-'
					&& tab[a->memory][i + 1]))
				error_message_free_args(tab);
			i++;
		}
		n = ft_atoi_long(tab[a->memory]);
		if ((n > 0 && n > 2147483647) || (n < 0 && n < -2147483648))
			error_message_free_args(tab);
		a->memory++;
	}
	args_finalize(a, b, tab, 1);
}

void			args_check_multi(t_stack *a, t_stack *b, char **argv)
{
	int			k;
	int			i;
	long int	n;

	k = 1;
	while (argv[k])
	{
		i = 0;
		while (argv[k][i])
		{
			if (!ft_isdigit(argv[k][i]) && !(i == 0 && argv[k][i] == '-'
											&& argv[k][i + 1]))
				error_message();
			i++;
		}
		n = ft_atoi_long(argv[k]);
		if ((n > 0 && n > 2147483647) || (n < 0 && n < -2147483648))
			error_message();
		k++;
		a->memory++;
	}
	args_finalize(a, b, argv + 1, 0);
}
