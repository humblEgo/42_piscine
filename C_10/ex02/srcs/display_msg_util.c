/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:49:36 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/10 22:13:58 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		print_filename(char *arg, int argc, int newline_flag)
{
	if (argc == 4)
		return (1);
	if (newline_flag == 1)
		ft_putstr("\n");
	ft_putstr("==> ");
	ft_putstr(arg);
	ft_putstr(" <==\n");
	return (1);
}

void	ft_put_open_error(char *arg, char *pname, int err_num, int order)
{
	ft_putstr(basename(pname));
	ft_putstr(": ");
	ft_putstr(arg);
	ft_putstr(": ");
	ft_putstr(strerror(err_num));
	if (order != 3)
		ft_putstr("\n");
}

void	ft_put_offset_error(char *arg, char *pname)
{
	char *line1;

	line1 = ": illegal offset -- ";
	ft_putstr(basename(pname));
	ft_putstr(line1);
	ft_putstr(arg);
	ft_putstr("\n");
}

void	ft_put_argu_error(char *arg, char *pname)
{
	char *line1;
	char *line2;

	line1 = ": option requires an argument -- ";
	line2 = "usage: tail [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]";
	ft_putstr(basename(pname));
	ft_putstr(line1);
	ft_putstr(&arg[1]);
	ft_putstr("\n");
	ft_putstr(line2);
	ft_putstr("\n");
}

void	stdin_read(int fd, char *tail_num)
{
	char	*buf;
	int		tail_size;
	int		tmp;
	int		idx;

	tail_size = ft_atoi(tail_num);
	buf = (char *)malloc(sizeof(char) * tail_size);
	errno = 0;
	idx = 0;
	while (read(fd, &buf[idx % tail_size], 1) != 0)
	{
		if (errno)
		{
			free(buf);
			return ;
		}
		idx++;
	}
	tmp = idx % tail_size;
	if (idx > tmp)
		write(1, &buf[tmp], tail_size - tmp);
	write(1, buf, tmp);
	free(buf);
	return ;
}
