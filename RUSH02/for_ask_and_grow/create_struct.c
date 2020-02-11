/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:11:03 by mykang            #+#    #+#             */
/*   Updated: 2020/02/11 12:43:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rush02.h"

bool	check_valid_arg(char *str);
d_s		*create_dict_buf(int fd);
int		check_mem_alloc(char *buf);
d_s		*parse_dict(char *dict, int line_cnt);
char	*new_parse_dict(char *dict);
int		remove_space_len(char *dict);
void	find_key(char *ptr, char sep, d_s *d_s_array);
char	*find_value(char *ptr, char sep, d_s *d_s_array);
void	ft_memset(char *buf, int len);

d_s		*g_d_s;

int		main(int argc, char *argv[])
{
	int fd;
	d_s *res;
	int test_cnt = -1;

	if (argc != 2 && argc != 3)
		write(1, "Error\n", 6);
	else
	{
		if (argc == 2)
		{
			if (!check_valid_arg(argv[argc - 1]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			else
			{
				fd = open("numbers.dict", O_RDONLY);
				if (fd == -1)
				{
					write(1, "Error\n", 6);
					close(fd);
					return (0);
				}
				res = create_dict_buf(fd);
				// ------- test struct array --------------
				test_cnt = -1;
				while (++test_cnt < 42)
				{
					printf("key[%d] : %s\n", test_cnt, res[test_cnt].key);
					printf("value[%d] : %s\n", test_cnt, res[test_cnt].value);
				}
			}
		}
		// need check later
		else
		{
			if (!check_valid_arg(argv[argc - 1]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			fd = open(argv[argc - 1], O_RDONLY);
			if (fd == -1)
			{
				write(1, "Error\n", 6);
				close(fd);
				return (0);
			}
			close(fd);
		}
	}
	return (0);
}

// ----------- 12 lines ------------
bool	check_valid_arg(char *str)
{
	while (*str != '\0')
	{
		if (*str == '0')
			return (false);
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

d_s	*create_dict_buf(int fd)
{
	char buf;
	char *dict;
	int char_cnt;
	int line_cnt;
	int new_fd;
	d_s *res;

	char_cnt = 0;
	line_cnt = 0;
	while (read(fd, &buf, 1) && ++char_cnt)
		if (buf == '\n')
			line_cnt++;
	dict = (char *)malloc(sizeof(char) * (char_cnt + 1));
	if (!check_mem_alloc(dict))
	{	
		return (res);
	}
	ft_memset(dict, char_cnt + 1);
	new_fd = open("numbers.dict", O_RDONLY);
	read(new_fd, dict, char_cnt);
	dict[char_cnt] = '\0';
	res = parse_dict(dict, line_cnt);
	return (res);
}

int		check_mem_alloc(char *buf)
{
	if (buf == NULL)
	{
		free(buf);
		return (0);
	}
	return (1);
}

d_s		*parse_dict(char *dict, int line_cnt)
{
	d_s		*d_s_array;
	char	*new_dict;
	int		idx;

	idx = 0;
	new_dict = new_parse_dict(dict);
	d_s_array = (d_s *)malloc(sizeof(d_s) * (line_cnt + 1));
	while (*new_dict)
	{
		find_key(new_dict, ':', &d_s_array[idx]);
		new_dict = find_value(new_dict, ':', &d_s_array[idx]);
		printf("key[%d] : %s\n", idx, d_s_array[idx].key);
		printf("value[%d] : %s\n", idx, d_s_array[idx].value);
		new_dict++;
		idx++;
	}
	d_s_array[idx].key[0] = '\0';
	d_s_array[idx].value[0] = '\0';
	return (d_s_array);
}

char	*new_parse_dict(char *dict)
{
	char	*temp;
	int		len;

	len = remove_space_len(dict) + 1;

	temp = (char *)malloc(sizeof(char) * len);
	char *ptr = temp;
	if (!check_mem_alloc(temp))
		free(temp);
	ft_memset(temp, len);
	while (*dict != '\0')
	{
		while (*dict != ' ' && *dict != ':')
		{
			*temp = *dict;
			temp++;
			dict++;
		}
		while (*dict == ' ')
			dict++;
		if (*dict == ':')
		{
			*temp = *dict;
			dict++;
			temp++;
		}
		if (*dict == ' ')
		{
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
					break;
				}
			}
		}
		else
		{
			while (*dict != '\n' && *dict != '\0')
			{
				*temp = *dict;
				temp++;
				dict++;
			}
			dict++;
		}
	}
	*temp = '\0';
	return (ptr);
}

int		remove_space_len(char *dict)
{
	int len;

	len = 0;
	while (*(dict++) != '\0' && ++len)
	{		// always meet key character
		if (*dict == ' ')	// when meet 0 to n spaces
			while (*dict != ':')
				dict++;
		else if (*dict == ':')  // when meet seperator (:)
			dict++;
		if (*dict == ' ')  // when meet 0 to n spaces
		{
			while (*dict == '\n' || *dict == '\0')
			{
				if (*dict == '\0')
					break ;
				dict++;
			}
		}
		else if (*dict == '\n')  // when meet new line (\n)
			dict++;
		if (*dict == '\0')
			break ;
	}
	return (len);
}

void	find_key(char *ptr, char sep, d_s *d_s_array)
{
	int idx;

	idx = 0;
	while (ptr[idx] != sep)
		idx++;
	d_s_array->key = (char *)malloc(sizeof(char) * (idx + 1));
	ft_memset(d_s_array->key, (idx + 1));
	idx = 0;
	while (ptr[idx] != sep)
	{
		d_s_array->key[idx] = ptr[idx];
		idx++;
	}
	d_s_array->key[idx] = '\0';
}

char	*find_value(char *ptr, char sep, d_s *d_s_array)
{
	int idx;
	int val_len;
	int s_idx;

	idx = 0;
	s_idx = 0;
	val_len = 0;
	while (ptr[idx] != sep)
		idx++;
	idx++;
	while (ptr[idx] != '\n' && ptr[idx] != '\0')
	{
		idx++;
		val_len++;
	}
	d_s_array->value = (char *)malloc(sizeof(char) * (val_len + 1));
	ft_memset(d_s_array->value, (val_len + 1));
	idx = 0;
	while (*ptr != sep)
		ptr++;
	ptr++;
	while (*ptr != '\n' && *ptr != '\0')
	{
		d_s_array->value[s_idx] = *ptr;
		ptr++;
		s_idx++;
		if (*ptr == '\0')
		{
			ptr--;
			break ;
		}
	}
	d_s_array->value[s_idx] = '\0';
	return (ptr);
}

void	ft_memset(char *buf, int len)
{
	int cnt;

	cnt = 0;
	while(cnt < len)
	{
		buf[cnt] = '\0';
		cnt++;
	}
}
