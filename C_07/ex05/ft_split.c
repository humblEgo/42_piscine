/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:10:59 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/06 10:21:02 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i])
		if (c == *(charset + i))
			return (1);
	return (0);
}

int		ft_str_era(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*str_malloc_cpy(char *str, char *charset)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && !(is_sep(str[i], charset)))
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str && !(is_sep(*str, charset)))
	{
		dest[i] = *str;
		str++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		words_space;

	words_space = ft_str_era(str, charset);
	res = (char **)malloc(sizeof(char *) * (words_space + 1));
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !(is_sep(*str, charset)))
		{
			res[i] = str_malloc_cpy(str, charset);
			i++;
			while (*str && !(is_sep(*str, charset)))
				str++;
		}
	}
	res[words_space] = 0;
	return (res);
}
