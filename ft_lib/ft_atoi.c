/* *********************************************** */
/*                                                 */
/*                                                 */
/*   ft_atoi.c                                     */
/*   Created: 2018/06/25 18:42:02 by vehsuga       */
/*                                                 */
/* *********************************************** */

int		ft_atoi(char *str)
{
	int negative;
	int res;

	res = 0;
	negative = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			negative = 1;
	while (*str > 47 && *str < 58)
		res = (res * 10) + (*(str++) - '0');
	if (negative)
		res *= -1;
	return (res);
}
