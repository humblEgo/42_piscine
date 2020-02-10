/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:30:33 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/31 22:49:16 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

int		compare(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] - b[i] > 0)
			return (1);
		else if (a[i] == b[i])
			i++;
		else
			return (0);
	}
	if (a[i] - b[i] > 0)
		return (1);
	return (0);
}

void	swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_by_ascii(int size, char *argv[])
{
	int i;
	int j;

	i = 0;
	while (i + 1 < size)
	{
		j = 1;
		while (j < size - 1)
		{
			if (compare(argv[j] + 0, argv[j + 1] + 0))
			{
				swap(&argv[j], &argv[j + 1]);
			}
			j++;
		}
		size--;
	}
}

int		main(int argc, char *argv[])
{
	int i;
	int j;

	sort_by_ascii(argc, argv);
	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (*(*(argv + i) + j))
		{
			putchar(*(*(argv + i) + j));
			j++;
		}
		putchar('\n');
		i++;
	}
	return (0);
}
