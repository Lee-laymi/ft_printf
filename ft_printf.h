/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:13:47 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/09 00:02:13 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *typ, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbrd(int nb);
int	ft_putnbrh(size_t n, size_t base, char t);
int	ft_printfsub(const char *typ, va_list args);

#endif
