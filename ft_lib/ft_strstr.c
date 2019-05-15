/* *********************************************** */
/*                                                 */
/*                                                 */
/*   ft_strstr.c                                   */
/*   Created: 2018/06/25 21:03:49 by vehsuga       */
/*                                                 */
/* *********************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp_n;
	char	*tmp_s;

	while (*str)
	{
		tmp_n = to_find;
		tmp_s = str;
		while (*tmp_s && *(tmp_s++) == *tmp_n)
			tmp_n++;
		if (!(*tmp_n))
			return (str);
		str = tmp_s;
	}
	return (0);
}
