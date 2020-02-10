/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:14:43 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 23:19:22 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	look_dict(char *str)
{
	int fd;
	int str_len;

	str_len = getlen(str);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		close(fd);
		return ;
	}
	create_dict_buf(str, fd, str_len);
	close(fd);
}

void	look_new_dict(char *dict, char *str)
{
	int fd;
	int	str_len;

	str_len = getlen(str);
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		close(fd);
		return ;
	}
	create_dict_buf(str, fd, str_len);
	close(fd);
}

int		is_valid_arg(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '0' && i == 0 && str[i + 1] != '\0')
			return (0);
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc == 2 && is_valid_arg(argv[argc - 1]))
		look_dict(argv[1]);
	else if (argc == 3 && is_valid_arg(argv[argc - 1]))
		look_new_dict(argv[1], argv[2]);
	else
		write(1, "Error\n", 6);
	return (0);
}
