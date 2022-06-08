/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfc1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:33:33 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/09 00:02:19 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (*s != 0)
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}

int	ft_putnbrd(int nb)
{
	long int	n;
	int			i;

	n = nb;
	i = 0;
	if (n == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		i += ft_putnbrd(147483648);
	}
	else if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbrd(-n);
	}
	else if (n < 10)
		i += ft_putchar(n + '0');
	else
	{
		i += ft_putnbrd(n / 10);
		i += ft_putnbrd(n % 10);
	}
	return (i);
}

int	ft_putnbrh(size_t n, size_t base, char t)
{
	int	i;

	i = 0;
	if (n >= base)
	{
		i += ft_putnbrh(n / base, base, t);
		i += ft_putnbrh(n % base, base, t);
	}
	else
	{
		if (t == 'x' || t == 'u' || t == 'p')
			i += write(1, &"0123456789abcdef"[n], 1);
		else if (t == 'X')
			i += write(1, &"0123456789ABCDEF"[n], 1);
	}
	return (i);
}
