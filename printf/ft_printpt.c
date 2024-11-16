/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:27:54 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/10 23:23:08 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr, int first)
{
	unsigned long	num;
	char			*hex;
	int				count;

	count = 0;
	if (!ptr)
		return (ft_printstr("(nil)"));
	if (first == 0)
		count += ft_printstr("0x");
	first++;
	num = (unsigned long)ptr;
	hex = "0123456789abcdef";
	if (num >= 16)
		count += ft_print_ptr((void *)(num / 16), first);
	ft_printchar(hex[num % 16]);
	return (count + 1);
}
