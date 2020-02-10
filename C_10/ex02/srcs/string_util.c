/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:01:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/10 18:36:58 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

int		ft_strcmp(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

int		ft_atoi(char *str)
{
	int idx;
	int num;

	num = 0;
	idx = 0;
	while (str[idx])
	{
		num *= 10;
		num += str[idx] - '0';
		idx++;
	}
	return (num);
}
