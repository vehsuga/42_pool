/* *********************************************** */
/*                                                 */
/*                                                 */
/*   ft_putnbr.c                                   */
/*   Created: 2018/06/21 22:57:11 by vehsuga       */
/*                                                 */
/* *********************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char c;

	//hacky, but well int limitations
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr);
	}
	else if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		c = nbr % 10 + '0';
		ft_putnbr(nbr / 10);
		write(1, &c, 1);
	}
}
