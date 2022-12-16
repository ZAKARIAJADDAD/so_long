/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:01:53 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/15 14:05:03 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_unsnbr(unsigned int nb)
{
	int	lent;

	lent = 0;
	if (nb >= 10)
	{
		lent += ft_putnbr(nb / 10);
		lent += ft_putchar((nb % 10) + 48);
	}
	else if (nb <= 9)
		lent += ft_putchar(nb + 48);
	return (lent);
}

int	ft_putnbr(int nb)
{
	int	lent;

	lent = 0;
	if (nb >= 10)
	{
		lent += ft_putnbr(nb / 10);
		lent += ft_putchar((nb % 10) + 48);
	}
	else if (nb == -2147483648)
	{
		lent += ft_putchar('-');
		lent += ft_putchar('2');
		lent += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		lent += ft_putchar('-');
		lent += ft_putnbr(nb * (-1));
	}
	else if (nb <= 9)
		lent += ft_putchar(nb + 48);
	return (lent);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_hexdecimal(unsigned long nb, char *base)
{
	int	lent;

	lent = 0;
	if (nb >= 16)
	{
		lent += ft_hexdecimal(nb / 16, base);
		lent += ft_hexdecimal(nb % 16, base);
	}
	else
		lent += ft_putchar(base[nb]);
	return (lent);
}