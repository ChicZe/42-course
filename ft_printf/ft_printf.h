/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <cristianiusca13@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:53:10 by ciusca            #+#    #+#             */
/*   Updated: 2023/11/10 16:13:25 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

int		ft_toupper(int c, int change);
int		n_len(unsigned int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(char *str);
int		ft_itoa(long cifra);
int		ft_printf_uns(unsigned int cifra);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_putnbr(long int nb);
int		ft_putstr(char *s);
int		hexa_converter(unsigned int n, int change);
int		printf_hex(unsigned long long ptr);

#endif