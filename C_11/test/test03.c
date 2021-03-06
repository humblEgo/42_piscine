
#include <stdio.h>
#include <stdlib.h>

//ex00: int	ft_foreach(int *tab, int length, void(*f)(int));
//ex01: int	*ft_map(int *tab, int length, int (*f)(int));
//ex02: int	ft_any(char **tab, int (*f)(char *));
//ex03
int	ft_count_if(char **tab, int length, int (*f)(char*));

int		is_42(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		if (a[i] == '0')
			return (1);
		i++;
	}
	return (0);
}


int main(void)
{
	char **tabs;
	int (*f)(char *);
	int nbrs;

	tabs = (char **)malloc(sizeof(char *) * 5);
	tabs[0] = "01234";
	tabs[1] = "123450";
	tabs[2] = "123405";
	tabs[3] = "123450";
	tabs[4] = "123450";
	f = is_42;
	nbrs = ft_count_if(tabs, 5, f);
	printf("%d\n", nbrs);
	return (0);
}
