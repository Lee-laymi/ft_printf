/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:24:59 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/02 00:39:03 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(0);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putchar(n / 10);
		ft_putchar(n % 10);
	}
	else
		ft_putchar( n + '0');
}
