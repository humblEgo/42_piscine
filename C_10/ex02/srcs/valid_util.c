/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:34:27 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/10 21:27:13 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_is_num(char *num_str)
{
	while (*num_str)
	{
		if (!(*num_str >= '0' && *num_str <= '9'))
			return (0);
		num_str++;
	}
	return (1);
}

int	is_valid_opt(char *option)
{
	char	*c_opt;

	c_opt = "-c";
	if (ft_strcmp(option, c_opt) != 0)
		return (0);
	return (1);
}

int	ft_is_dir(char *target)
{
	int		fd;
	char	test;

	errno = 0;
	fd = open(target, O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		read(fd, &test, 1);
		if (errno)
		{
			close(fd);
			return (1);
		}
		close(fd);
		return (0);
	}
}
