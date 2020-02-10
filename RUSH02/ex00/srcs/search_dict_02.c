/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dict_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:20:42 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 23:22:15 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		go_free(char *l_str, char *l_str_zero, char *r_str, char *digit)
{
	free(l_str);
	free(l_str_zero);
	free(r_str);
	free(digit);
	return (1);
}

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
