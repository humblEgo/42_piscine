/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:11:03 by mykang            #+#    #+#             */
/*   Updated: 2020/02/11 12:52:16 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	create_dict_buf(char *str, int fd, int str_len)
{
	char	buf;
	char	*dict;
	int		char_cnt;
	int		line_cnt;
	int		new_fd;

	char_cnt = 0;
	line_cnt = 0;
	while (read(fd, &buf, 1) && ++char_cnt)
		if (buf == '\n')
			line_cnt++;
	dict = (char *)malloc(sizeof(char) * (char_cnt + 1));
	ft_memset(dict, char_cnt + 1);
	new_fd = open("numbers.dict", O_RDONLY);
	read(new_fd, dict, char_cnt);
	dict[char_cnt] = '\0';
	if (!check_repit_key(parse_dict(dict, line_cnt)))
		return ;
	srch_str(str, parse_dict(dict, line_cnt), str_len, 0);
}

t_dic	*parse_dict(char *dict, int line_cnt)
{
	t_dic	*t_dic_array;
	char	*new_dict;
	int		idx;

	idx = 0;
	new_dict = new_parse_dict(dict);
	t_dic_array = (t_dic *)malloc(sizeof(t_dic) * (line_cnt + 1));
	while (*new_dict)
	{
		find_key(new_dict, ':', &t_dic_array[idx]);
		new_dict = find_value(new_dict, ':', &t_dic_array[idx]);
		new_dict++;
		idx++;
	}
	t_dic_array[idx].key[0] = '\0';
	t_dic_array[idx].value[0] = '\0';
	return (t_dic_array);
}

void	cpy_struct(char *temp, char *dict)
{
	while (*dict != '\0')
	{
		while (*dict != ' ' && *dict != ':')
			*(temp++) = *(dict++);
		while (*dict == ' ')
			dict++;
		*(temp++) = *(dict++);
		while (*dict == ' ')
			dict++;
		while (*dict != '\n' && *dict != 0)
		{
			*(temp++) = *(dict++);
			if (*dict == '\n')
			{
				*(temp++) = *(dict++);
				break ;
			}
			if (*dict == '\0')
			{
				*temp = *dict;
				break ;
			}
		}
	}
	*temp = '\0';
}

char	*new_parse_dict(char *dict)
{
	char	*temp;
	char	*ptr;

	temp = (char *)malloc(sizeof(char) * (remove_space_len(dict) + 1));
	ptr = temp;
	if (!check_mem_alloc(temp))
		free(temp);
	ft_memset(temp, (remove_space_len(dict) + 1));
	cpy_struct(temp, dict);
	return (ptr);
}

int		remove_space_len(char *dict)
{
	int len;

	len = 0;
	while (*(dict++) != '\0' && ++len)
	{
		if (*dict == ' ')
			while (*dict != ':')
				dict++;
		else if (*dict == ':')
			dict++;
		if (*dict == ' ')
		{
			while (*dict == '\n' || *dict == '\0')
			{
				if (*dict == '\0')
					break ;
				dict++;
			}
		}
		else if (*dict == '\n')
			dict++;
		if (*dict == '\0')
			break ;
	}
	return (len);
}
