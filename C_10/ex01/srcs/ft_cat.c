/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:13:51 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/13 20:00:06 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	str_echo(void)
{
	char buf;

	while (read(0, &buf, 1) != 0)
		write(1, &buf, 1);
}

int		ft_is_error(int err_num, char *path, char *pname)
{
	if (err_num)
	{
		ft_puterror(err_num, path, pname);
		return (1);
	}
	else
		return (0);
}

void	ft_display_file(int fd, char *path, char *pname)
{
	char	buf;

	while (read(fd, &buf, 1))
	{
		if (ft_is_error(errno, path, pname))
			return ;
		write(1, &buf, 1);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;

	if (argc == 1)
		str_echo();
	else
	{
		i = 0;
		while (++i < argc)
		{
			errno = 0;
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				ft_puterror(errno, argv[i], argv[0]);
				continue ;
			}
			ft_display_file(fd, argv[i], argv[0]);
			close(fd);
		}
	}
	return (0);
}
