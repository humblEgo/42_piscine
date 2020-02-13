/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:50:47 by sanam             #+#    #+#             */
/*   Updated: 2020/02/12 23:44:52 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_get_map_filesize(char *map)
{
	int		fd;
	int		count;
	char	buf;

	fd = open(map, O_RDWR);
	if (fd < 0)
		return (0);
	count = 0;
	while (read(fd, &buf, 1))
		count++;
	close(fd);
	return (count);
}

void	ft_cpy_map_to_buf(char *map_buf, char *map, int map_fsize)
{
	int fd;

	if ((fd = open(map, O_RDONLY)) < 0)
		return ;
	read(fd, map_buf, map_fsize);
	map_buf[map_fsize] = '\0';
	close(fd);
}

int		ft_get_line_len(char *line_strt_addr)
{
	int len;

	len = 0;
	while (line_strt_addr[len] != '\n')
	{
		if (line_strt_addr[len] == '\0')
			return (-1);
		len++;
	}
	return (len);
}

int		ft_is_valid_map(char *map)
{
	int		map_fsize;
	char	*map_buf;
	int		valid_result;

	map_fsize = ft_get_map_filesize(map);
	if (map_fsize == 0)
		return (0);
	if (!(map_buf = (char *)malloc(sizeof(char) * map_fsize)))
		return (0);
	ft_cpy_map_to_buf(map_buf, map, map_fsize);
	valid_result = (ft_is_valid_map_buf(map_buf)) ? 1 : 0;
	free(map_buf);
	return (valid_result);
}
