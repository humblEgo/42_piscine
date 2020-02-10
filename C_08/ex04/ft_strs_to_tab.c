/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:24:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/04 20:18:58 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *av)
{
	int i;

	i = 0;
	while (*(av + i))
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int		src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!(dest))
		return (0);
	i = 0;
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_av;
	int			i;

	s_av = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(s_av))
		return (0);
	i = 0;
	while (av[i] != 0 && i < ac)
	{
		s_av[i].size = ft_strlen(*(av + i));
		s_av[i].str = *(av + i);
		s_av[i].copy = ft_strdup(*(av + i));
		i++;
	}
	s_av[i].str = 0;
	return (s_av);
}
