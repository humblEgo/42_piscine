/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_check1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:47:50 by sanam             #+#    #+#             */
/*   Updated: 2020/02/12 23:48:09 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_is_valid_map_marks(char *mark_addr, char *ascii)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if (mark_addr[i] <= 31 || mark_addr[i] == 127)
			return (0);
		if (ascii[(int)mark_addr[i]] != 0)
			return (0);
		if (ascii[(int)mark_addr[i]] == 0)
			ascii[(int)mark_addr[i]] += 1;
	}
	if (mark_addr[2] <= 31 || mark_addr[2] == 127 ||
			ascii[(int)mark_addr[2]] != 0)
		return (0);
	return (1);
}

int		ft_is_valid_lines_num(char *map_buf, int line_len, int *atoied_num)
{
	int i;
	int total;

	i = -1;
	total = 0;
	while (++i < line_len - 3)
	{
		if (!(map_buf[i] >= '0' && map_buf[i] <= '9'))
			return (0);
		total += map_buf[i] - '0';
	}
	if (total == 0)
		return (0);
	atoied_num[0] = ft_natoi(map_buf, line_len - 3);
	return (1);
}

int		ft_is_valid_chars(char *map_buf, char *ascii)
{
	int i;

	ascii['\n'] = 1;
	i = -1;
	while (map_buf[++i])
		if (ascii[(int)map_buf[i]] != 1)
			return (0);
	return (1);
}

int		ft_is_valid_cols_rows(char *map_addr, int *atoied_num)
{
	int frst_line_len;
	int	i;
	int	row_count;

	frst_line_len = ft_get_line_len(map_addr);
	row_count = 0;
	i = -1;
	while (map_addr[++i])
	{
		if (ft_get_line_len(&map_addr[i]) != frst_line_len)
			return (0);
		i += frst_line_len;
		row_count++;
	}
	if (row_count == 0 || row_count != atoied_num[0])
		return (0);
	return (1);
}

int		ft_is_valid_map_buf(char *map_buf)
{
	int		fst_line_len;
	int		i;
	char	ascii[255];
	int		atoied_num[1];

	atoied_num[0] = 0;
	i = -1;
	while (++i < 255)
		ascii[i] = 0;
	fst_line_len = ft_get_line_len(map_buf);
	if (fst_line_len < 4 || fst_line_len > 17)
		return (0);
	if (!ft_is_valid_map_marks(&map_buf[fst_line_len - 3], ascii))
		return (0);
	if (!ft_is_valid_lines_num(map_buf, fst_line_len, atoied_num))
		return (0);
	if (!ft_is_valid_chars(&map_buf[fst_line_len + 1], ascii))
		return (0);
	if (!ft_is_valid_cols_rows(&map_buf[fst_line_len + 1], atoied_num))
		return (0);
	return (1);
}
