/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:20:43 by meyami            #+#    #+#             */
/*   Updated: 2017/11/08 18:20:46 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int i;
	int len;

	i = 0;
	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}
