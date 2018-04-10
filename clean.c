/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:50:38 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 17:50:39 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		clean_redundancy(char *s1, char *s2)
{
	if ((ft_strequ(s1, "ra") && ft_strequ(s2, "rra"))
			|| (ft_strequ(s1, "rra") && ft_strequ(s2, "ra"))
			|| (ft_strequ(s1, "rb") && ft_strequ(s2, "rrb"))
			|| (ft_strequ(s1, "rrb") && ft_strequ(s2, "rb"))
			|| (ft_strequ(s1, "pa") && ft_strequ(s2, "pb"))
			|| (ft_strequ(s1, "pb") && ft_strequ(s2, "pa")))
		return (1);
	else
		return (0);
}

char	*clean_mixable(char *s1, char *s2)
{
	if ((ft_strequ(s1, "ra") && ft_strequ(s2, "rb"))
			|| (ft_strequ(s1, "rb") && ft_strequ(s2, "ra")))
		return (ft_strdup("rr"));
	else if ((ft_strequ(s1, "sa") && ft_strequ(s2, "sb"))
			|| (ft_strequ(s1, "sb") && ft_strequ(s2, "sa")))
		return (ft_strdup("ss"));
	else if ((ft_strequ(s1, "rra") && ft_strequ(s2, "rrb"))
			|| (ft_strequ(s1, "rrb") && ft_strequ(s2, "rra")))
		return (ft_strdup("rrr"));
	else
		return (0);
}

int		clean_wide_enough(t_instruct *instructions)
{
	if (instructions && instructions->next && instructions->next->next
		&& instructions->next->next->next)
		return (1);
	return (0);
}

void	clean_free_instruction(t_instruct *instructions)
{
	free(instructions->instruction);
	free(instructions);
}

void	clean_instructions(t_instruct *instructions)
{
	t_instruct	*next;
	t_instruct	*next_next;
	char		*new;

	if (!clean_wide_enough(instructions))
		return ;
	clean_instructions(instructions->next);
	next = instructions->next;
	next_next = instructions->next->next;
	if (clean_wide_enough(instructions)
		&& clean_redundancy(next->instruction, next_next->instruction))
	{
		instructions->next = next_next->next;
		clean_free_instruction(next);
		clean_free_instruction(next_next);
	}
	else if (clean_wide_enough(instructions)
		&& (new = clean_mixable(next->instruction, next_next->instruction)))
	{
		clean_free_instruction(next);
		free(next_next->instruction);
		next_next->instruction = new;
		instructions->next = next_next;
	}
}
