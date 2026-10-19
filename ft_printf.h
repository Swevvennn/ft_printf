/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:41 by mosmond           #+#    #+#             */
/*   Updated: 2025/11/06 11:29:05 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putnbr_hex(unsigned long long n, int u);
int	ft_put_adress(void *ptr);

int	ft_putchar(char c);
int	ft_printf(const char *str, ...);
int	ft_sending(char s, va_list args);

#endif