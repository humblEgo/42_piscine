/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dict2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:29:32 by kycho             #+#    #+#             */
/*   Updated: 2020/02/09 17:20:15 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
** this function frees allocations.
** @param  char *a : allocated memory address.
** @param  char *b : allocated memory address.
** @param  char *c : allocated memory address.
** @param  char *d : allocated memory address.
** @return int     : always return 1.
*/

int		go_free(char *l_str, char *l_str_zero, char *r_str, char *digit)
{
	free(l_str);
	free(l_str_zero);
	free(r_str);
	free(digit);
	return (1);
}

/*
** this function allocates sufficient memory for a copy of the string str,
** and add ‘0’ character to fit the given size
** does the copy, adding ‘0’ and returns memory address.
** @param   char *str : given string.
** @param   int size  : full length for copy and adding ‘0’.
** @return  char *    : allocated memory address.
*/

char	*tail_add_zero(char *str, int size)
{
	int		i;
	int		str_len;
	char	*new_str;

	str_len = getlen(str);
	new_str = malloc(size + 1);
	new_str = ft_strcpy(new_str, str);
	i = str_len;
	while (i < size)
	{
		new_str[i] = '0';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
** this function prints a value by given numeric key string(char *str) and
** if given numeric string(char *str) is a multiple of 10 except for “10”,
** then prints a value of “1” before prints a value of given numeric string.
** @param  char *str  : given numeric string.
** @param  t_dic *arr : t_dic struct array(consisting of a given dictionary)
** @return int        : always return 1
*/

int		check_print_value(char *str, t_dic *arr)
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
