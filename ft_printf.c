/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:18:29 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/07 22:49:59 by skrairab         ###   ########.fr       */
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
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (*s != 0)
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}

int	ft_putnbrD(int nb)
{
	long	n;
	int	i;

	n = nb;
	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbrD(-n);
	}
	else if (n >= 10)
	{
		i += ft_putnbrD(n / 10);
		i += ft_putnbrD(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putnbrH(unsigned int n, unsigned int base, char t)
{
	int	i;
	
	i = 0;

	if (n >= base)
	{
		i += ft_putnbrH(n / base, base, t);
		i += ft_putnbrH(n % base, base, t);
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

int	ft_printf(const char *typ, ...)
{
	int	i;
	va_list args;
	va_start(args, typ);

	i = 0;
	while (*typ)
	{
		if (*typ == '%' && *(typ + 1) == 'c')
		{
			i += ft_putchar(va_arg(args, int));
			typ++;
		}
		else if (*typ == '%' && *(typ + 1) == 's')
		{
			i += ft_putstr(va_arg(args, char *));
			typ++;
		}
		else if (*typ == '%' && *(typ + 1) == 'p')
		{
			write(1, &"0x", 1);
			i += ft_putnbrH(va_arg(args, unsigned int),16 ,'p');
			typ++;
		}
		else if (*typ == '%' && (*(typ + 1) =='d' || *(typ+ 1) == 'i'))
		{
			i += ft_putnbrD(va_arg(args, int));
			typ++;
		}
		else if (*typ == '%' && *(typ + 1) == 'u')
		{
			i += ft_putnbrH(va_arg(args, unsigned int),10 ,'u');
			typ++;
		}
		else if (*typ == '%' && (*(typ + 1) == 'x' || *(typ + 1) == 'X'))
		{
			i += ft_putnbrH(va_arg(args, unsigned int),16 ,'x');
			i += ft_putnbrH(va_arg(args, unsigned int),16 ,'X');
			typ++;
		}
		else if (*typ == '%' && *(typ +1) == '%')
		{
			i += write(1, "%", 1);
			typ++;
		}  
		else
			i += ft_putchar(*typ);		
		++typ;
	}
	va_end(args);
	return (i);
}

//int	main(void)
//{

//	ft_printf("%c\n", '0');
//	printf("%c\n", '0');

//	ft_printf(" %c\n ", '0');
//	printf(" %c\n ", '0');

//	ft_printf(" %c ", '0');
//	printf(" %c ", '0');

//	ft_printf(" %c\n", '0' - 256);
//	printf(" %c\n", '0' - 256);

//	ft_printf("%c\n ", '0' + 256);
//	printf("%c\n ", '0' + 256);
//
//
//	printf(" NULL %s NULL\n ", NULL);
//	ft_printf(" NULL %s NULL\n ", NULL);



/*	TEST(3, print(" %c", '0' - 256));$
	TEST(4, print("%c ", '0' + 256));$
	TEST(5, print(" %c %c %c ", '0', 0, '1'));$
	TEST(6, print(" %c %c %c ", ' ', ' ', ' '));$
	TEST(7, print(" %c %c %c ", '1', '2', '3'));$
	TEST(8, print(" %c %c %c ", '2', '1', 0));$
	TEST(9, print(" %c %c %c ", 0, '1', '2'));$
	cout << ENDL;

	*/
//}
