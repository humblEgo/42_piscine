/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:47:35 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 17:19:39 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
** this function allocates sufficient memory for left split
** numeric string by spliter(index), does the copy of left side of
** numeric string, and returns the memory address.
** @param   int spliter :  index to split string.
** @param   char *str   :  given numeric string to split.
** @return  char *      : allocated memory address.
*/

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

/*
** this function allocates sufficient memory for right split
** numeric string by spliter(index), does the copy of right side of
** numeric string, and returns the memory address.
** @param   int spliter :  index to split string.
** @param   char *str   :  given numeric string to split.
** @param   int str_len :  length of the numeric string.
** @return  char *      :  allocated memory address.
*/

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

/*
** this function allocates sufficient memory for string of digits in
** the spliter position. does make the digits and, returns the memory address.
** @param   int spliter :  index to split string.
** @param   int str_len :  length of given numeric string.
** @return  char *      :  allocated memory address.
*/

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

/*
** this function is main recursive function to print numeric string
** with words in a dictionary.
** @param   char *str   : given numeric string.
** @param   t_dic *arr  : t_dic struct array(consisting of a given dictionary)
** @param   int str_len : length of the numeric string.
** @param   int spliter : index to split string for recursive process.
** @return  int			 : always return 1
*/

int		srch_str(char *str, t_dic *arr, int str_len, int spliter)
{
	char	*l_str_zero;
	char	*l_str;
	char	*r_str;
	char	*dg;

	if (is_key(str, arr) && check_print_value(str, arr))
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
