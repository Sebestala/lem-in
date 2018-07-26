#include <stdio.h>
#include "libft/src/libft.h"
#include "includes/lem_in.h"

void	fct(t_lst *lst)
{
	lst = lst->next;
	printf("%d\n", lst->id);
	lst->id = 48;
	printf("%d\n", lst->id);
}

int		main()
{
	t_lst	lst;
	t_lst	lst2;
	t_lst	lst3;

	lst.id = 42;
	lst2.id = 84;
	lst3.id = 101;
	lst.next = &lst2;
	lst2.next = &lst3;
	printf("%d\n", lst.id);
	fct(&lst);
	printf("%d\n", lst.next->id);
	



	return (0);
}
