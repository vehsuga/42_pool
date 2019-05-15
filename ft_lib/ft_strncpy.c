/* *********************************************** */
/*                                                 */
/*                                                 */
/*   ft_strncpy.c                                  */
/*   Created: 2018/06/25 20:51:30 by vehsuga       */
/*                                                 */
/* *********************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *tmp;

	tmp = dest;
	while (n--)
		if(*src)
			*(tmp++) = *(src++);
		else
			*(tmp++) = 0;
	return (dest);
}
