/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:09:22 by sanam             #+#    #+#             */
/*   Updated: 2020/02/12 19:46:16 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_strlen(char *src)
{
	int		len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest);
}

int		ft_atoi(char *str)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1 * sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0') * sign;
		str++;
	}
	return (res);
}

int		ft_natoi(char *str, int n)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1 * sign;
		str++;
	}
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') && (i < n))
	{
		res = res * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (res);
}
