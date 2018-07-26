#include <stdio.h>
#include "libft/src/libft.h"
#include "includes/lem_in.h"

int		main()
{
char	*str = "Hello world !";
char	*str1;
char	*str2;
char	**str3;
void	*str4;
t_ant	*ant;
t_ant	*ant2;

	str1 = ft_strdup(str);
	str2 = str1;
	str3 = &str1;
	ant = ft_memalloc(sizeof(t_ant));
	str4 = &ant;
	ft_putstr(str);
	ft_putstr("\n");
	ft_putstr(str+2);
	ft_putstr("\n");
	ft_putstr(str);
	ft_putstr("\n");

printf("char = %lu\n", sizeof(char));
printf("char * = %lu\n", sizeof(char *));
printf("char ** = %lu\n", sizeof(char **));
printf("int = %lu\n", sizeof(int));
printf("int * = %lu\n", sizeof(int *));
printf("int ** = %lu\n", sizeof(int **));
printf("size_t = %lu\n", sizeof(size_t));
printf("size_t * = %lu\n", sizeof(size_t *));
printf("long = %lu\n", sizeof(long));
printf("long * = %lu\n", sizeof(long *));
printf("long long = %lu\n", sizeof(long long));
printf("long long * = %lu\n", sizeof(long long *));
printf("t_lst  = %lu\n", sizeof(t_lst));
printf("t_lst * = %lu\n", sizeof(t_lst *));
printf("t_ant  = %lu\n", sizeof(t_ant));
printf("t_ant * = %lu\n", sizeof(t_ant *));
printf("str = %lu\n", sizeof(str));
printf("str * = %lu\n", sizeof(*str));
printf("str1 = %lu\n", sizeof(str1));
printf("str1 * = %lu\n", sizeof(*str1));
printf("str1 = %p\n", str1);
printf("*str1 = %d\n", *str1);
printf("&str1 = %p\n", &str1);
printf("str2 = %s\n", str2);
printf("str3 = %s\n", *str3);
printf("str4 = %p\n", str4);
printf("ant = %p\n", ant);
printf("ant2 = %p\n", ant2);

printf("\nunsigned char = %lu\n", sizeof(unsigned char));
printf("unsigned char * = %lu\n", sizeof(unsigned char *));
printf("unsigned char ** = %lu\n", sizeof(unsigned char **));
printf("unsigned int = %lu\n", sizeof(unsigned int));
printf("unsigned int * = %lu\n", sizeof(unsigned int *));
printf("unsigned int ** = %lu\n", sizeof(unsigned int **));
printf("unsigned long = %lu\n", sizeof(unsigned long));
printf("unsigned long * = %lu\n", sizeof(unsigned long *));
printf("unsigned long long = %lu\n", sizeof(unsigned long long));
printf("unsigned long long * = %lu\n", sizeof(unsigned long long *));
return (0);
}
