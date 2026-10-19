/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:25 by mosmond           #+#    #+#             */
/*   Updated: 2025/11/06 11:56:04 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_sending(char s, va_list args)
{
	if (s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'p')
		return (ft_put_adress(va_arg(args, void *)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == 'u')
		return (ft_putnbr_u((unsigned int)va_arg(args, unsigned int)));
	else if (s == 'x' || s == 'X')
		return (ft_putnbr_hex((unsigned long long)va_arg(args, unsigned int), \
		(s == 'x')));
	else if (s == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		sum;
	int		i;

	i = -1;
	sum = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			sum += ft_sending(str[++i], args);
		else
			sum += ft_putchar(str[i]);
	}
	va_end(args);
	return (sum);
}

// int	main(void)
// {
// 	int n = -10;
// 	printf("\n%u", (ft_printf("%d", n) == printf("%d", n)));
// }
