
#include <stdio.h>
#include <stdlib.h>

void	ft_sort_string_tab(char **tab);
int		ft_strcmp(char *a, char *b);	//tested!
void	ft_swap(char **a, char **b);	//tested!

int	main(void)
{
	char **tab;

	tab = (char **)malloc(sizeof(char *) * 5);

	tab[0] = "123";
	tab[1] = "adfasg";
	tab[2] = "zjkz";
	tab[3] = "0123456";
	tab[4] = 0;
	ft_sort_string_tab(tab);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", tab[i]);
	}
	printf("===========answer============\n");
	printf("0123456\n");
	printf("0123456789\n");
	printf("adfasg\n");
	printf("zjzkdlj\n");
	free(tab);
	return (0);
}
