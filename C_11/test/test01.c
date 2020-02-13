
#include <stdio.h>
#include <stdlib.h>

//ex00: int	ft_foreach(int *tab, int length, void(*f)(int));
//ex01:
int	*ft_map(int *tab, int length, int (*f)(int));

int		ft_put_minus(int i)
{
	return (i*(-1));
}


int main(void)
{
	int tab[5] = {12, 15, 42, 23, 77};
	int length;
	int (*f)(int);
	int *nbrs;

	length = 5;
	f = ft_put_minus;
	nbrs = ft_map(tab, length, f);
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", *(nbrs + i));
	}
	free(nbrs);
	return (0);
}
