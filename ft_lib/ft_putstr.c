/* *********************************************** */
/*                                                 */
/*                                                 */
/*   ft_putstr.c                                   */
/*   Created: 2018/06/22 15:02:57 by vehsuga       */
/*                                                 */
/* *********************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
