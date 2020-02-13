/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:11:32 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/07 11:46:28 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int num)
{
	unsigned int	num_us;
	int				a;

	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	num_us = (unsigned int)num;
	if (num_us >= 10)
		ft_putnbr(num_us / 10);
	a = (int)(num_us % 10) + '0';
	write(1, &a, 1);
}

int		is_space(char c)
{
	if (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ')
		return (1);
	return (0);
}

int		is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int		is_numberic(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int idx;
	int num;
	int sign;

	sign = 1;
	num = 0;
	idx = 0;
	while (str[idx] && is_space(str[idx]))
		idx++;
	while (str[idx] && is_sign(str[idx]))
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] && is_numberic(str[idx]))
	{
		num *= 10;
		num += (sign * (str[idx] - '0'));
		idx++;
	}
	return (num);
}
