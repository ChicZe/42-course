/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:44:12 by ciusca            #+#    #+#             */
/*   Updated: 2024/04/25 16:17:15 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_error(char *str, int quit)
{
	printf("%s\n", str);
	return (quit);
}

int	check_args(char **argv)
{
	char	*str;
	int		time;
	int		i;

	i = 0;
	while (argv[++i])
	{
		time = ft_atoi(argv[i]);
		str = ft_itoa(time);
		if (ft_strncmp(str, argv[i], ft_strlen(argv[i])) != 0)
		{
			free(str);
			printf(YELLOW);
			return (ft_error("\ninvalid argument!\n", 0));
			printf(NONE);
		}
		free(str);
	}
	return (1);
}
