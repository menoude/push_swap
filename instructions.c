/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:13:01 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:28 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions_print(t_instruct *instructions)
{
	if (!instructions)
		return ;
	ft_putendl(instructions->instruction);
	instructions_print(instructions->next);
	free(instructions->instruction);
	free(instructions);
}

void	instructions_enqueue(t_stack *a, t_stack *b, char *new_instruct)
{
	t_instruct *ptr;

	if (!a->instructions)
	{
		a->instructions = malloc(sizeof(t_instruct));
		if (!a->instructions)
			error_message_free_stacks(a, b);
		a->instructions->instruction = ft_strdup(new_instruct);
		a->instructions->next = 0;
	}
	else
	{
		ptr = a->instructions;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_instruct));
		if (!ptr->next)
			error_message_free_stacks(a, b);
		ptr = ptr->next;
		ptr->instruction = ft_strdup(new_instruct);
		ptr->next = 0;
	}
}


void	instructions_exec(t_stack *a, t_stack *b, char *new_instruct)
{
	if (ft_strequ(new_instruct, "sa") || ft_strequ(new_instruct, "sb")
			|| ft_strequ(new_instruct, "ss"))
		op_swap(a, b, new_instruct[1]);
	else if (ft_strequ(new_instruct, "pa") || ft_strequ(new_instruct, "pb"))
		op_push(a, b, new_instruct[1]);
	else if (ft_strequ(new_instruct, "ra") || ft_strequ(new_instruct, "rb")
			|| ft_strequ(new_instruct, "rr"))
		op_rotate(a, b, new_instruct[1]);
	else if (ft_strequ(new_instruct, "rra") || ft_strequ(new_instruct, "rrb")
			|| ft_strequ(new_instruct, "rrr"))
		op_reverse_rotate(a, b, new_instruct[2]);
	else
		error_message_free_stacks(a, b);
	instructions_enqueue(a, b, new_instruct);
}

void		instructions_read(t_stack *a, t_stack *b, int verbose)
{
	char *instruct;

	instruct = 0;
	while (get_next_line(0, &instruct) > 0)
	{
		instructions_exec(a, b, instruct);
		if (verbose)
		{
			ft_printf("\n              %s\n", instruct);
			print_stacks(a, b);
		}
		free(instruct);
	}
}
