/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:30:35 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/04 21:15:26 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
		return (0);
	else
	{
		res = (int *)malloc(sizeof(int) * (max - min));
		if (!res)
			return (0);
		i = 0;
		while (min + i < max)
		{
			res[i] = min + i;
			i++;
		}
	}
	return (res);
}
