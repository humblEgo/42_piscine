/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/05 17:20:50 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			check_base(char *base);
int			ft_atoi_base(char *str, char *base);

long long	digit_base_nbr(long long nbr_ll, long long base_len)
{
	long long digit_count;

	if (nbr_ll == 0)
		return (1);
	digit_count = 0;
	while (nbr_ll != 0)
	{
		nbr_ll = nbr_ll / base_len;
		digit_count++;
	}
	return (digit_count);
}

void		dc_cvrt(int nb_deci, char *base_to, long long base_len, char **res)
{
	long long str_size;
	long long nbr_ll;
	long long i;

	i = -1;
	str_size = 1;
	nbr_ll = (long long)nb_deci;
	if (nb_deci < 0)
	{
		str_size = 2;
		nbr_ll *= (-1);
	}
	str_size += digit_base_nbr(nbr_ll, base_len);
	*res = (char *)malloc(sizeof(char) * (str_size));
	if (nb_deci < 0)
		i = 0;
	(*res)[0] = '-';
	(*res)[--str_size] = '\0';
	while (i < --str_size)
	{
		(*res)[str_size] = base_to[nbr_ll % base_len];
		nbr_ll /= base_len;
	}
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			nb_deci;
	int			base_from_len;
	long long	base_to_len;
	char		*res;

	nb_deci = ft_atoi_base(nbr, base_from);
	base_from_len = check_base(base_from);
	base_to_len = (long long)check_base(base_to);
	if (base_to_len == 0 || base_from_len == 0)
		return (0);
	dc_cvrt(nb_deci, base_to, base_to_len, &res);
	return (res);
}
