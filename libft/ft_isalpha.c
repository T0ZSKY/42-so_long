/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isalpha.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tomlimon <tomlimon@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/04 11:32:51 by tomlimon		  #+#	#+#			 */
/*   Updated: 2024/11/05 15:10:05 by tomlimon		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		return (0);
	return (1);
}
