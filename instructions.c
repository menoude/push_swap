/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:13:01 by meyami            #+#    #+#             */
/*   Updated: 2018/03/29 15:13:22 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions_enqueue(t_stack *a, t_stack *b, t_instruct **instructions,
													char *new_instruct)
{
	(void)a;
	(void)b;
	if (!*instructions)
	{
		*instructions = malloc(sizeof(t_instruct));
		// if (!instructions)
			// ; //faire un truc !!!!
	}
	else
	{
		while ((*instructions)->next)
			*instructions = (*instructions)->next;
		(*instructions)->next = malloc(sizeof(t_instruct));
		// if (!*instructions->next)
			// ; //faire un truc !!!
		*instructions = (*instructions)->next;
	}
	(*instructions)->instruction = ft_strdup(new_instruct);
	(*instructions)->next = 0;
}

void	instructions_print(t_instruct *lst)
{
		t_instruct	*ptr;
		t_instruct	*previous;

		ptr = lst;
		previous = 0;
		if (!ptr)
			return;
		while (ptr->next)
		{
			previous = ptr;
			ptr = ptr->next;
		}
		ft_putendl(ptr->instruction);
		free(ptr->instruction);
		free(ptr);
		if (previous)
			previous->next = 0;
}

void	instructions_exec(t_stack *a, t_stack *b, t_instruct **lst, char *new_instruct)
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
	instructions_enqueue(a, b, lst, new_instruct);
	// print_stacks(a, b);
	counter++;
}

void		instructions_read(t_stack *a, t_stack *b)
{
	char *instruct;
	t_instruct *instructions;

	instructions = 0;
	instruct = 0;
	while (get_next_line(0, &instruct) > 0)
	{
		instructions_exec(a, b, &instructions, instruct);
		free(instruct);
	}
}
