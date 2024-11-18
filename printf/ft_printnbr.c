/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printnbr.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tomlimon <tomlimon@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/10 14:38:21 by tomlimon		  #+#	#+#			 */
/*   Updated: 2024/11/10 23:19:53 by tomlimon		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		count += ft_printchar('-');
		count += ft_printnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		count += ft_printnbr(nbr / 10);
		count += ft_printchar(nbr % 10 + '0');
	}
	else
		count += ft_printchar(nbr + '0');
	return (count);
}
