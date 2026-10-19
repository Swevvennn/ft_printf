/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:29:37 by mosmond           #+#    #+#             */
/*   Updated: 2025/11/06 11:54:23 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		sum += ft_putchar(s[i++]);
	return (sum);
}

int	ft_putnbr_hex(unsigned long long n, int u)
{
	int	text;
	int	sum;

	sum = 0;
	if (n > 15)
		sum = ft_putnbr_hex(n / 16, u);
	if (n % 16 < 10)
		text = n % 16 + '0';
	else if (u == 0)
		text = n % 16 + '7';
	else if (u == 1)
		text = n % 16 + 'W';
	write(1, &text, 1);
	return (sum + 1);
}

int	ft_put_adress(void *ptr)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_putnbr_hex((unsigned long long)ptr, 1) + 2);
}

int	ft_putnbr(int n)
{
	int	text;
	int	sum;

	sum = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648"));
		else
		{
			sum = 1;
			write(1, "-", 1);
			n = -n;
		}
	}
	if (n > 9)
		sum += ft_putnbr(n / 10);
	text = n % 10 + '0';
	write(1, &text, 1);
	return (sum + 1);
}

int	ft_putnbr_u(unsigned int n)
{
	int	text;
	int	sum;

	sum = 0;
	if (n > 9)
		sum = ft_putnbr(n / 10);
	text = n % 10 + '0';
	write(1, &text, 1);
	return (sum + 1);
}
