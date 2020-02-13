/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:49:36 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/12 18:41:21 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	stdin_read_zero(void)
{
	char buf;

	while (read(1, &buf, 1))
		continue;
}

void	stdin_read(int fd, char *tail_num)
{
	char	*buf;
	int		tail_size;
	int		tmp;
	int		idx;

	if ((tail_size = ft_atoi(tail_num)) == 0)
		return (stdin_read_zero());
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
