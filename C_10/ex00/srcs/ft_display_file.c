/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:37:09 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/08 11:19:25 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_putstr(char *error)
{
	while (*error)
	{
		write(1, error, 1);
		error++;
	}
}

int		print_error(int error_case)
{
	char *error1;
	char *error2;
	char *error3;

	error1 = "File name missing.";
	error2 = "Too many arguments.";
	error3 = "Cannot read file.";
	if (error_case == 1)
		ft_putstr(error1);
	else if (error_case == 2)
		ft_putstr(error2);
	else if (error_case == 3)
		ft_putstr(error3);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[1024];

	if (argc == 1)
		return (print_error(1));
	else if (argc > 2)
		return (print_error(2));
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (print_error(3));
		read(fd, buf, MAX - 1);
		ft_putstr(buf);
		close(fd);
	}
	return (0);
}
