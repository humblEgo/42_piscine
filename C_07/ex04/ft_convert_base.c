/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:26:44 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/05 10:44:06 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
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

int	check_base(char *base)
{
	int idx;
	int overlap[255];

	if (!(base[0]))
		return (0);
	if (!(base[1]))
		return (0);
	idx = -1;
	while (++idx < 255)
		*(overlap + idx) = 0;
	idx = -1;
	while (base[++idx])
	{
		if (base[idx] == '-' || base[idx] == '+' || is_white_space(base[idx]))
			return (0);
		overlap[(int)base[idx]] += 1;
		if (overlap[(int)base[idx]] > 1)
			return (0);
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
		num += (sign) * index_from_base(str[idx++], base);
	}
	return (num);
}
