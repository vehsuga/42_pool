/* *********************************************** */
/*                                                 */
/*                                                 */
/*   ft_strcpy.c                                   */
/*   Created: 2018/06/25 20:05:19 by vehsuga       */
/*                                                 */
/* *********************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char *tmp;

	tmp = dest;
	while (*src)
		*(tmp++) = *(src++);
	*tmp = 0;
	return (dest);
}
