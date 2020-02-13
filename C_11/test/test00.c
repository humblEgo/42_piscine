
#include <stdio.h>

void	ft_foreach(int *tab, int length, void(*f)(int));

void	ft_putnbr(int i)
{
	printf("%d\n", i);
}


int main(void)
{
	int tab[5] = {12, 15, 42, 23, 77};
	int length;
	void (*f)(int);

	length = 5;
	f = ft_putnbr;
	ft_foreach(tab, length, f);
	return (0);
}
