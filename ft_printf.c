/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:28:25 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/21 15:58:49 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *typ, ...)
{
	int			i;
	va_list		args;

	va_start(args, typ);
	i = 0;
	while (*typ)
	{
		if (*typ == '%')
		{
			i += ft_printfsub(typ, args);
			typ++;
		}
		else
			i += ft_putchar(*typ);
		typ++;
	}
	va_end(args);
	return (i);
}
