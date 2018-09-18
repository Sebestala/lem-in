
#include "libft.h"
#include <stdio.h>

char	*strnew_del(size_t size, char *str)
{
	int		i;

	i = 0;
	ft_strdel(&str);
	str = NULL;
//	if (size < 4294967295)
	{
		if (!(str = (char *)malloc((size + 1) * sizeof(char))))
			return (NULL);
		while (i <= (int)size)
		{
			str[i] = '\0';
			i++;
		}
	}
//	else
//		return (NULL);
	return (str);
}
