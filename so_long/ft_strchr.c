/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:07:06 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/02 13:44:14 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	while (s && (unsigned char)*s != (unsigned char)c && *s)
		s++;
	if (*s == '\0' && (unsigned char)c != '\0')
		return (NULL);
	return ((char *)s);
}
