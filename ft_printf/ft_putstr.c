/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <cristianiusca13@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:23:17 by ciusca            #+#    #+#             */
/*   Updated: 2023/11/09 17:34:53 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		i;
	int		count;
	int		len;
	char	*str;

	len = 0;
	count = 0;
	i = 0;
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	str = malloc(sizeof(char *) * len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i ++;
		count++;
	}
	free(str);
	return (count);
}
