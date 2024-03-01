/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:08:35 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/01 15:21:28 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char)*s != (unsigned char)c && *s)
		s++;
	if (*s == '\0' && (unsigned char)c != '\0')
		return (NULL);
	return ((char *)s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = -1;
	if ((int)start > (int)ft_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		if (substr == NULL)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	s += start;
	if ((int)ft_strlen(s) <= (int)len)
		substr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (s[++i] != '\0' && i < len)
		substr[i] = s[i];
	substr[i] = '\0';
	return (substr);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*arr;
	int		i;

	i = -1;
	if (nitems != 0 && size > ULONG_MAX / nitems)
		return (NULL);
	arr = (void *)malloc(size * nitems);
	if (arr == NULL)
		return (NULL);
	while ((size_t)++i < nitems * size)
		arr[i] = 0;
	return (arr);
}
