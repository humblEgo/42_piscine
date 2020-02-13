
#include <stdio.h>
#include <stdlib.h>

//ex00: int	ft_foreach(int *tab, int length, void(*f)(int));
//ex01: int	*ft_map(int *tab, int length, int (*f)(int));
//ex02: int	ft_any(char **tab, int (*f)(char *));
//ex03: int	ft_count_if(char **tab, int length, int (*f)(char*));
//ex04
int	ft_is_sort(int *tab, int length, int (*f)(int, int));

#include <stdio.h>

int		is_smaller(int a, int b)
{
	if (a > b)
		return (-1);
	else if (a == b)
		return (0);
	else
		return (1);
}

int main(void)
{
	int *tabs;
	int (*f)(int, int);
	int nbrs;

	tabs = (int *)malloc(sizeof(int) * 5);
	tabs[0] = 1;
	tabs[1] = 2;
	tabs[2] = 2;
	tabs[3] = 3;
	tabs[4] = 4;  
	f = is_smaller; 
	nbrs = ft_is_sort(tabs, 5, f);
	printf("%d\n", nbrs);
	free(tabs);
	return (0);
}
