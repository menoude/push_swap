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

void	clean_instructions(t_instruct *instructions)
{
	t_instruct	*remove_next;
	t_instruct	*remove_next_next;
	char		*new_instruct;

	if (!instructions->next->next->next)
		return ;
	clean_instructions(instructions->next);
	remove_next = instructions->next;
	remove_next_next = instructions->next->next;
	if (clean_redundancy(instructions->next->instruction,
				instructions->next->next->instruction))
	{
		instructions->next = instructions->next->next->next;
		free(remove_next_next->instruction);
		free(remove_next_next);
	}
	if ((new_instruct = clean_mixable(instructions->next->instruction,
					instructions->next->next->instruction)))
	{
		free(remove_next);
		instructions->next = instructions->next->next;
		free(instructions->next->instruction);
		instructions->next->instruction = new_instruct;
	}
}
