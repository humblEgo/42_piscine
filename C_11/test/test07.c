
#include <stdio.h>
#include <stdlib.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

int		ft_strcmp(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

int	main(void)
{
	char **tab;
	int (*cmp)(char *, char *);

	tab = (char **)malloc(sizeof(char *) * 1);
	tab[0] = 0;
/*
	tab[0] = "KBqU";
	tab[1] = "VbJeD";
	tab[2] = "FxHa2y3";
	tab[3] = "JtZVeSwp";
	tab[4] = "9cqsip4A";
	tab[5] = "IOR0lgWvr";	
	tab[6] = "K7Y6yTdBF";
	tab[7] = "efb5nJrdDVc";
	tab[8] = "ahAvZBnKc1T";
	tab[9] = "7mo6GJsvyzE";
	tab[10] = "JXAGRFinTwl";
	tab[11] = "MkX3hEPAUoj2";
	tab[12] = 0;
*/
	cmp = ft_strcmp;
	ft_advanced_sort_string_tab(tab, cmp);
	for (int i = 0; i < 1; i++)
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
