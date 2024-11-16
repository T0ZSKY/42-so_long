/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:33:12 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/10 23:24:27 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_type(va_list args, char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar((int) va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr((char *)va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr((void *) va_arg(args, void *), 0);
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr((int) va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned((unsigned int)
				va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex((unsigned int)
				va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_type(args, *str);
		}
		else
			count += ft_printchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
