/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:18:29 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/02 00:51:07 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "ft_printf.h"*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(0);
}

void	ft_putstr(char *s)
{
	while (*s != 0)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putchar(n / 10);
		ft_putchar(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void ft_printf(const char *typ, ...)
{
	va_list args;
	va_start(args, typ);

	while (*typ)
	{
		if (*typ == '%' && *(typ + 1) == 'c')
		{
			ft_putchar(va_arg(args, int));
			typ++;
		}
		else if (*typ == '%' && *(typ + 1) == 's')
		{
			ft_putstr(va_arg(args, char *));
			typ++;
		}
//		else if (*typ == '%' && *(typ + 1) == 'p')
//		{
//			ft_putnbr(va_arg(args, int));
//			typ++;
//		}
		else if (*typ == '%' && *(typ + 1) =='d')
		{
			ft_putnbr(va_arg(args, int));
			typ++;
		}
/*		else if (*typ == 'i')
		{
			int c = va_arg(args, int);
			printf("%i\n", c);
		}
		else if (*typ == 'u')
		{
			int u = va_arg(args, int);
			printf("%u\n", u);
		}
		else if (*typ == 'x')
		{
			int x = va_arg(args, int);
			printf("%x\n", x);
		}
		else if (*typ == 'X')
		{
			int X = va_arg(args, int);
			printf("%X\n", X);
		}
		else if (*typ == '%')
		{
			int % = va_arg(args, char);
			printf("%%\n", %);
		}   */
		else
			ft_putchar(*typ);		
		++typ;
	}
	va_end(args);
}

int	main(void)
{
	ft_printf("%c Hello! \n", 'a');
	printf("%c Hello! \n", 'a');

	ft_printf("%s Hello world! \n", "b");
	printf("%s Hello world! \n", "b");

//	ft_printf("%p Hello world! \n", "b");}
//	printf("%p Hello world! \n", "b");
//
//
	ft_printf("%d 13142342! \n", 1);
//
	printf("%d 13142342! \n", 1);
}

