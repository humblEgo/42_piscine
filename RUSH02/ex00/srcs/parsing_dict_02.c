/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:12:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 23:16:52 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		check_mem_alloc(char *buf)
{
	if (buf == NULL)
	{
		free(buf);
		return (0);
	}
	return (1);
}

void	ft_memset(char *buf, int len)
{
	int cnt;

	cnt = 0;
	while (cnt < len)
	{
		buf[cnt] = '\0';
		cnt++;
	}
}

void	find_key(char *ptr, char sep, t_dic *t_dic_array)
{
	int idx;

	idx = 0;
	while (ptr[idx] != sep)
		idx++;
	idx = 0;
	while (ptr[idx] != sep)
	{
		t_dic_array->key[idx] = ptr[idx];
		idx++;
	}
	t_dic_array->key[idx] = '\0';
}

char	*find_value(char *ptr, char sep, t_dic *t_dic_array)
{
	int idx;
	int val_len;
	int s_idx;

	idx = 0;
	s_idx = 0;
	val_len = 0;
	while (ptr[idx] != sep)
		idx++;
	while (ptr[++idx] != '\n' && ptr[idx] != '\0')
		val_len++;
	while (*ptr != sep)
		ptr++;
	while (*(++ptr) != '\n' && *ptr != '\0')
	{
		t_dic_array->value[s_idx] = *ptr;
		s_idx++;
		if (*ptr == '\0')
		{
			ptr--;
			break ;
		}
	}
	t_dic_array->value[s_idx] = '\0';
	return (ptr);
}
