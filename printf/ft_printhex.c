/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:36:55 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/10 23:03:32 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, char format)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_print_hex(nbr / 16, format);
	if (nbr % 16 < 10)
		count += ft_printchar(nbr % 16 + '0');
	else
	{
		if (format == 'x')
			count += ft_printchar(nbr % 16 + 'a' - 10);
		else
			count += ft_printchar(nbr % 16 + 'A' - 10);
	}
	return (count);
}
