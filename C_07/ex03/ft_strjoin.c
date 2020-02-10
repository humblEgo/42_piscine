/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:49:18 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/05 17:19:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		import_str_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		meager_total_len(int size, char **strs, char *sep)
{
	int	i;
	int j;
	int strs_len;
	int	sep_len;

	sep_len = import_str_len(sep);
	strs_len = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			strs_len++;
	}
	return (strs_len + ((size - 1) * sep_len));
}

void	ft_strcpy(char **strs, char *sep, char *res, int size)
{
	int i;
	int j;
	int k;

	i = -1;
	k = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			res[++k] = strs[i][j];
		if (i != size - 1)
		{
			j = -1;
			while (sep[++j])
				res[++k] = sep[j];
		}
	}
	res[++k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		total_len;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char) * 1);
		res[0] = '\0';
	}
	else
	{
		total_len = meager_total_len(size, strs, sep) + 1;
		res = (char *)malloc(sizeof(char) * total_len);
		ft_strcpy(strs, sep, res, size);
	}
	return (res);
}
