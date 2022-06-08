/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:07:40 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/09 00:02:16 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfsub(const char *typ, va_list args)
{
	int	i;

	i = 0;
	if (*(typ + 1) == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*(typ + 1) == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*(typ + 1) == 'p')
	{
		i += write(1, &"0x", 2);
		i += ft_putnbrh(va_arg(args, size_t), 16, 'p');
	}
	else if (*(typ + 1) == 'd' || *(typ + 1) == 'i')
		i += ft_putnbrd(va_arg(args, int));
	else if (*(typ + 1) == 'u')
		i += ft_putnbrh(va_arg(args, unsigned int), 10, 'u');
	else if (*(typ + 1) == 'x' || *(typ + 1) == 'X')
		i += ft_putnbrh(va_arg(args, unsigned int), 16, *(typ + 1));
	else if (*(typ + 1) == '%')
		i += write(1, "%", 1);
	return (i);
}
