/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:59:19 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/30 10:06:18 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	long_long_print(long long nb, char *base)
{
	write(1, &base[nb], 1);
}

int		base_check(char *base)
{
	int idx;
	int cmp_idx;

	if (base[0] == '\0')
		return (0);
	if (base[1] == '\0')
		return (0);
	idx = 0;
	while (base[idx] != '\0')
	{
		if (base[idx] == '-' || base[idx] == '+')
			return (0);
		cmp_idx = idx + 1;
		while (base[cmp_idx])
		{
			if (base[idx] == base[cmp_idx])
			{
				return (0);
			}
			cmp_idx++;
		}
		idx++;
	}
	return (idx);
}

void	longlong_putnbr_base(long long nbr_long, char *base, long long base_len)
{
	if (nbr_long < 0)
	{
		write(1, "-", 1);
		nbr_long *= -1;
		longlong_putnbr_base(nbr_long, base, base_len);
	}
	else
	{
		if (nbr_long >= base_len)
			longlong_putnbr_base(nbr_long / base_len, base, base_len);
		long_long_print(nbr_long % base_len, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long nbr_long;
	long long base_len;

	base_len = (long long)base_check(base);
	if (base_len <= 1)
		return ;
	nbr_long = (long long)nbr;
	longlong_putnbr_base(nbr_long, base, base_len);
}
