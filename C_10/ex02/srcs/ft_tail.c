/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:03:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/10 21:54:45 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	display_file_tail(int fd, int tail_size)
{
	char	*buf;
	int		idx;
	int		tmp;

	buf = (char *)malloc(sizeof(char) * tail_size);
	idx = 0;
	errno = 0;
	while (read(fd, &buf[idx % tail_size], 1))
	{
		if (errno)
			return ;
		idx++;
	}
	tmp = idx % tail_size;
	if (idx >= tail_size)
		write(1, &buf[tmp], tail_size - tmp);
	write(1, buf, tmp);
	free(buf);
}

void	display_files(int argc, char **argv, int tail_size)
{
	int i;
	int newline_flag;
	int fd;
	int err_num;

	newline_flag = 0;
	i = 2;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		err_num = errno;
		if (fd == -1)
		{
			ft_put_open_error(argv[i], argv[0], err_num, i);
			continue;
		}
		newline_flag = print_filename(argv[i], argc, newline_flag);
		display_file_tail(fd, tail_size);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	int tail_size;

	if (argc == 2 && is_valid_opt(argv[1]))
		ft_put_argu_error(argv[1], argv[0]);
	if (argc == 3 && is_valid_opt(argv[1]))
	{
		if (ft_is_num(argv[2]))
			stdin_read(0, argv[2]);
		else
			ft_put_offset_error(argv[2], argv[0]);
	}
	else if (argc > 3 && is_valid_opt(argv[1]))
	{
		if (!ft_is_num(argv[2]))
			ft_put_offset_error(argv[2], 0);
		else
		{
			tail_size = ft_atoi(argv[2]);
			display_files(argc, argv, tail_size);
		}
	}
	return (0);
}
