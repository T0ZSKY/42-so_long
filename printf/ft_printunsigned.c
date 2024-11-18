/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printunsigned.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tomlimon <tom.limon@>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/10 14:41:37 by tomlimon		  #+#	#+#			 */
/*   Updated: 2024/11/10 14:42:23 by tomlimon		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_print_unsigned(nbr / 10);
		count += ft_printchar(nbr % 10 + '0');
	}
	else
		count += ft_printchar(nbr + '0');
	return (count);
}
