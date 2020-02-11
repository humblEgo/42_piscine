/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:54:46 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 16:44:08 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
** this function finds a value in a dictionary array(t_dit *arr)
** by a key(char *str), then prints the value.
** @param char *str  : Key string to find the value in a dictionary.
** @param t_dic *arr : t_dic struct array ( consisting of a given dictionary)
** @return void      : Nothing (Display value string)
*/

void	put_value(char *str, t_dic *arr)
{
	int		i;

	if (g_order != 0)
		write(1, " ", 1);
	g_order += 1;
	i = -1;
	while (arr[++i].key)
	{
		if (ft_strcmp(str, arr[i].key) == 0)
		{
			ft_putstr(arr[i].value);
			break ;
		}
	}
}

/*
** this function checks if the key(char *key) is in the dict(t_dic *arr)
** @param char *key  :  Key string for check in dictionary
** @param t_dic *arr :  t_dic struct array( consisting of a given dictionary)
** @return  int      :  0 (false) , 1 (true)
*/

int		is_key(char *key, t_dic *arr)
{
	int	i;

	i = -1;
	while (arr[++i].key)
	{
		if (ft_strcmp(key, arr[i].key) == 0)
			return (1);
	}
	return (0);
}
