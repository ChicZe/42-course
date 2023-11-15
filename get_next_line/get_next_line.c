/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <cristianiusca13@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:26:10 by ciusca            #+#    #+#             */
/*   Updated: 2023/11/15 18:47:51 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "get_next_line_utils.c"

char	*trim_first_line(char *str)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	len = ft_strlen(str);
	len -= i - 1;
	temp = str;
	str = ft_substr(temp, i, len);
	free(temp);
	return (str);
}

char	*get_line(const char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		dup[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dup[i] = '\n';
		dup[i + 1] = 0;
	}
	else
		dup[i] = 0;
	return (dup);
}

char	*find_line(char *file, int fd)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	if (!file)
		file = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!file)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		temp = file;
		file = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (file);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	file = find_line(file, fd);
	if (!file)
		return (NULL);
	line = get_line(file);
	file = trim_first_line(file);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("example.txt", O_CREAT);
	next_line = get_next_line(fd);
	count++;
	printf("[%d]:%s\n", count, next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("[%d]:%s\n", 2, next_line);
	free(next_line);
	close(fd);
	return (0);
}