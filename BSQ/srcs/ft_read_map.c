/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:10:09 by hna               #+#    #+#             */
/*   Updated: 2020/02/12 23:54:07 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			ft_read_first_line(char *fpath, t_map_info *minfo)
{
	int		i;
	int		fd;
	char	buf[SIZE];

	i = 0;
	fd = open(fpath, O_RDONLY);
	if (fd < 0)
		return ;
	read(fd, buf, SIZE);
	while (buf[i] != '\n')
	{
		i++;
	}
	minfo->full = buf[i - 1];
	minfo->obs = buf[i - 2];
	minfo->empty = buf[i - 3];
	buf[i - 3] = '\0';
	minfo->row = ft_atoi(buf);
	close(fd);
}

t_map_info		*ft_get_map_info(char *fpath)
{
	int			fd;
	int			col;
	char		skip;
	t_map_info	*map_info;

	col = 0;
	if (!(map_info = malloc(sizeof(t_map_info))))
		return (0);
	ft_read_first_line(fpath, map_info);
	fd = open(fpath, O_RDONLY);
	if (fd < 0)
		return (0);
	read(fd, &skip, 1);
	while (skip != '\n')
		read(fd, &skip, 1);
	read(fd, &skip, 1);
	while (skip != '\n')
	{
		read(fd, &skip, 1);
		col++;
	}
	map_info->col = col;
	close(fd);
	return (map_info);
}

int				ft_get_filesize(char *fpath)
{
	int		fd;
	int		size;
	char	buf;

	size = 0;
	fd = open(fpath, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

void			ft_put_data(char *buf, t_map_info *minfo)
{
	int		i;
	int		r;
	int		c;

	i = 0;
	r = -1;
	while (buf[i] != '\n')
		i++;
	i++;
	while (++r < minfo->row)
	{
		c = -1;
		while (++c < minfo->col)
		{
			while (buf[i] != minfo->obs && buf[i] != minfo->empty)
				i++;
			if (buf[i] == minfo->obs)
			{
				i++;
				g_map[r][c] = 0;
			}
			else if (buf[i++] == minfo->empty)
				g_map[r][c] = 1;
		}
	}
}

void			ft_read_map(t_map_info *minfo, char *fpath)
{
	int		fd;
	int		size;
	char	*buf;

	ft_malloc_map(minfo);
	size = ft_get_filesize(fpath);
	if (!(buf = (char *)malloc(sizeof(char) * size)))
		return ;
	fd = open(fpath, O_RDONLY);
	if (fd < 0)
		return ;
	read(fd, buf, size);
	ft_put_data(buf, minfo);
	close(fd);
	free(buf);
}
