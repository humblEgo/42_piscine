/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:54:46 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 23:07:00 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	put_value(char *str, t_dic *arr)
{
	int		i;

	if (g_order != 0)
		write(1, " ", 1);
	g_order += 1;
	i = -1;
	while (arr[++i].key[0])
	{
		if (ft_strcmp(str, arr[i].key) == 0)
		{
			ft_putstr(arr[i].value);
			break ;
		}
	}
}

int		is_key(char *key, t_dic *arr)
{
	int	i;

	i = -1;
	while (arr[++i].key[0])
	{
		if (ft_strcmp(key, arr[i].key) == 0)
			return (1);
	}
	return (0);
}
