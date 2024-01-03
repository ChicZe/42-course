/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:39:58 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/03 18:20:15 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*remove_char(char *str, int c)
{
	char	*dup;
	int		i;
	int		j;

	dup = calloc(sizeof(char *), ft_len(str));
	if (!dup)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != c)
		{
			dup[j] = str[i];
			j++;
		}
	}
	return (dup);
}
