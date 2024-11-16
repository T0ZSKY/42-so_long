/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:47:11 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/10 23:22:38 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printstr(char *str);
int	ft_print_ptr(void *ptr, int first);
int	ft_print_hex(unsigned int nbr, char format);
int	ft_printnbr(int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_printpercent(void);
int	ft_printf(const char *str, ...);

#endif
