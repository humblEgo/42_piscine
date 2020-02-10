/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:47:35 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 23:21:40 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*split_left(int spliter, char *str)
{
	int		i;
	char	*l_str;

	l_str = (char *)malloc(sizeof(char) * spliter + 1);
	i = -1;
	while (++i < spliter)
	{
		l_str[i] = str[i];
	}
	l_str[i] = '\0';
	return (l_str);
}

char	*split_right(int spliter, char *str, int str_len)
{
	int		i;
	char	*r_str;

	while (str[spliter] == '0')
		spliter++;
	r_str = (char *)malloc(sizeof(char) * (str_len - spliter + 1));
	i = 0;
	while (spliter + i < str_len)
	{
		r_str[i] = str[spliter + i];
		i++;
	}
	r_str[i] = '\0';
	return (r_str);
}

char	*split_digit(int spliter, int str_len)
{
	int		i;
	char	*digit;
	int		size;

	size = str_len - spliter + 2;
	digit = (char *)malloc(sizeof(char) * size);
	i = -1;
	while (++i < size - 1)
		digit[i] = '0';
	digit[0] = '1';
	digit[i] = '\0';
	return (digit);
}

int		only_one_zeros_and_not_ten(char *str, t_dic *arr)
{
	int	i;
	int	flag;

	flag = 1;
	if (str[0] != '1')
		flag = 0;
	i = 0;
	while (str[++i])
		if (str[i] != '0')
			flag = 0;
	if (i == 2 || i == 1)
		flag = 0;
	if (flag == 1)
		put_value("1", arr);
	if (is_key(str, arr))
		put_value(str, arr);
	return (1);
}

int		srch_str(char *str, t_dic *arr, int str_len, int spliter)
{
	char	*l_str_zero;
	char	*l_str;
	char	*r_str;
	char	*dg;

	if (is_key(str, arr) && only_one_zeros_and_not_ten(str, arr))
		return (1);
	while (++spliter < str_len)
	{
		l_str = split_left(spliter, str);
		r_str = split_right(spliter, str, str_len);
		l_str_zero = tail_add_zero(l_str, str_len);
		dg = split_digit(spliter, str_len);
		if (is_key(l_str_zero, arr) || (is_key(dg, arr)))
		{
			if (is_key(l_str_zero, arr))
				srch_str(l_str_zero, arr, getlen(l_str_zero), 0);
			else if (is_key(dg, arr) && srch_str(l_str, arr, getlen(l_str), 0))
				put_value(dg, arr);
			srch_str(r_str, arr, getlen(r_str), 0);
			return (go_free(l_str, l_str_zero, r_str, dg));
		}
		go_free(l_str, l_str_zero, r_str, dg);
	}
	return (1);
}
