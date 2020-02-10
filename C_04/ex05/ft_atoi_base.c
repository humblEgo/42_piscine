/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:11:32 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/29 17:56:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	int flag;

	flag = 0;
	if (c == '\t' ||
		c == '\n' ||
		c == '\v' ||
		c == '\f' ||
		c == '\r' ||
		c == ' ')
		flag = 1;
	return (flag);
}

int	check_base(char *base)
{
	int idx;
	int cmp_idx;

	idx = 0;
	cmp_idx = 0;
	if (!(base[0]))
		return (0);
	if (!(base[1]))
		return (0);
	while (base[idx])
	{
		if (base[idx] == '-' || base[idx] == '+' || is_white_space(base[idx]))
			return (0);
		cmp_idx = idx + 1;
		while (base[cmp_idx])
		{
			if (base[idx] == base[cmp_idx])
				return (0);
			cmp_idx++;
		}
		idx++;
	}
	return (idx);
}

int	is_numberic(char c, char *base)
{
	int idx;

	idx = 0;
	while (base[idx])
	{
		if (c == base[idx])
			return (1);
		idx++;
	}
	return (0);
}

int	index_from_base(char c, char *base)
{
	int idx;

	idx = 0;
	while (base[idx])
	{
		if (c == base[idx])
			break ;
		idx++;
	}
	return (idx);
}

int	ft_atoi_base(char *str, char *base)
{
	int idx;
	int num;
	int sign;
	int base_len;

	sign = 1;
	idx = 0;
	num = 0;
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	while (str[idx] && is_white_space(str[idx]))
		idx++;
	while (str[idx] && (str[idx] == '-' || str[idx] == '+'))
		if (str[idx++] == '-')
			sign *= -1;
	if (!(is_numberic(str[idx], base)))
		return (num);
	while (str[idx] && is_numberic(str[idx], base))
	{
		num *= base_len;
		num += index_from_base(str[idx++], base);
	}
	num *= sign;
	return (num);
}
