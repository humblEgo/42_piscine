/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:06:11 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/12 18:06:24 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_error(char *error)
{
	while (*error)
		write(2, error++, 1);
}

void	ft_putstr(int fd)
{
	char buf;

	while (read(fd, &buf, 1))
		write(1, &buf, 1);
}

int		print_error(int error_case)
{
	char *error1;
	char *error2;
	char *error3;

	error1 = "File name missing.\n";
	error2 = "Too many arguments.\n";
	error3 = "Cannot read file.\n";
	if (error_case == 1)
		ft_putstr_error(error1);
	else if (error_case == 2)
		ft_putstr_error(error2);
	else if (error_case == 3)
		ft_putstr_error(error3);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		return (print_error(1));
	else if (argc > 2)
		return (print_error(2));
	else
	{
		fd = open(argv[1], O_RDWR);
		if (fd < 0)
		{
			close(fd);
			return (print_error(3));
		}
		ft_putstr(fd);
		close(fd);
	}
	return (0);
}
