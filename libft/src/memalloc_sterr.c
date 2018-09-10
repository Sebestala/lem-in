
#include "libft.h"

void	*memalloc_sterr(size_t size, char *str)
{
	void	*mall;

	if (size < 4294967295)
	{
		if ((mall = (void *)malloc((size + 1) * sizeof(void))) == 0)
		{
			ft_putstr_fd(2, "Error : dynamic allocation problem in ");
			exit_str(str);
		}
		ft_bzero(mall, size + 1);
	}
	else
	{
		ft_putstr_fd(2, "Error : problem size for dynamic allocation in ");
		exit_str(str);
	}
	return (mall);
}
