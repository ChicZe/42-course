/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:58:19 by ciusca            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:17 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_case(char c, va_list arg)
{
	int		count;

	count = 0;
	if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 'p')
		count += printf_hex(va_arg(arg, unsigned long long));
	else if (c == '%')
		count += write (1, "%", 1);
	return (count);
}

int	check_case(char c, va_list arg)
{
	long	count;

	count = 0;
	if (c == 'd')
		count += ft_itoa(va_arg(arg, int));
	else if (c == 'i')
		count += ft_itoa(va_arg(arg, int));
	else if (c == 'u')
		count += ft_printf_uns(va_arg(arg, unsigned int));
	else if (c == 'x')
		count += hexa_converter(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		count += hexa_converter(va_arg(arg, unsigned int), 1);
	else
		count += char_case(c, arg);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, str);
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			count += check_case(str[i + 1], arg);
			i++;
		}
		else
			count += write (1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}
