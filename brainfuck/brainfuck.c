/* *********************************************** */
/*                                                 */
/*                                                 */
/*   brainfuck.c                                   */
/*   Created: 2018/07/13 13:19:59 by vehsuga       */
/*                                                 */
/* *********************************************** */

#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 4096

char	*handle_obracket(char *pnt)
{
	int count;

	count = 0;
	while (count > -1)
	{
		pnt++;
		if (*pnt == ']' && count == 0)
			count = -1;
		else if (*pnt == '[')
			count++;
		else if (*pnt == ']' && count > 0)
			count--;
	}
	return pnt;
}

char	*handle_cbracket(char *pnt)
{
	int count;
	count = 0;
	while (count > -1)
	{
		pnt--;
		if (*pnt == '[' && count == 0)
			count = -1;
		else if (*pnt == ']')
			count++;
		else if (*pnt == '[' && count > 0)
			count--;
	}
	return pnt;
}

void	brainfuck_solve(char *source, char *buffer)
{
	while (*source)
	{
		if (*source == '>')
		{
			buffer++;
			source++;
		}
		else if (*source == '<')
		{
			buffer--;
			source++;
		}
		else if (*source == '+')
		{
			(*buffer)++;
			source++;
		}
		else if (*source == '-')
		{
			(*buffer)--;
			source++;
		}
		else if (*source =='.')
		{
			write(1, buffer, 1);
			source++;
		}
		else if (*source == '[')
		{
			if(*buffer == 0)
				source = handle_obracket(source);
			else
				source++;
		}
		else if (*source == ']')
		{
			if (*buffer != 0)
				source = handle_cbracket(source);
			else
				source++;
		}
		else
		{
			source++;
		}
	}
}

int		main(int argc, char **argv)
{
	char *buffer;
	if(argc > 1)
	{
		buffer = (char *)malloc(BUF_SIZE);
		brainfuck_solve(argv[1], buffer);
		free(buffer);
	}
	else
		write(1, "\n", 1);
	return (0);
}
