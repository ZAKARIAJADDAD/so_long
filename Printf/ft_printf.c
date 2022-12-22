/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:05:29 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/20 19:21:37 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_arg(char c, va_list pr, int lent)
{
	if (c == 'c')
		lent += ft_putchar(va_arg(pr, int));
	if (c == 's')
		lent += ft_putstr(va_arg(pr, char *));
	if (c == 'd' || c == 'i')
		lent += ft_putnbr(va_arg(pr, int));
	if (c == 'u')
		lent += ft_unsnbr(va_arg(pr, unsigned int));
	if (c == 'x')
		lent += ft_hexdecimal(va_arg(pr, unsigned int), "0123456789abcdef");
	if (c == 'X')
		lent += ft_hexdecimal(va_arg(pr, unsigned int), "0123456789ABCDEF");
	if (c == 'p')
	{
		lent += ft_putstr("0x");
		lent += ft_hexdecimal(va_arg(pr, unsigned long), "0123456789abcdef");
	}
	return (lent);
}

int	ft_printf(const char *arg, ...)
{
	int		i;
	int		lent;
	va_list	p;

	va_start(p, arg);
	i = 0;
	lent = 0;
	while (arg[i])
	{
		if (arg[i] == '%' && arg[i + 1] != '\0')
		{
			i++;
			if (arg[i] == '%')
				lent += ft_putchar('%');
			lent += check_arg(arg[i], p, 0);
		}
		else
			lent += ft_putchar(arg[i]);
		i++;
	}
	va_end(p);
	return (lent);
}