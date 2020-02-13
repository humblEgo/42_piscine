/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:15:20 by sanam             #+#    #+#             */
/*   Updated: 2020/02/12 23:55:17 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_init_str(char *str1, char *str2, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		str1[i] = 0;
		str2[i] = 0;
	}
}

void	fill_temp(char *buf_res)
{
	int i;
	int temp;

	temp = open("temp", O_CREAT | O_RDWR, 0777);
	if (temp < 0)
		return ;
	i = 0;
	while (buf_res[i])
		i++;
	buf_res[i - 1] = '\n';
	buf_res[i] = '\0';
	write(temp, buf_res, i + 1);
	close(temp);
}

void	ft_check_redirection(char *buf)
{
	int		i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			break ;
		if (i >= SIZE)
			g_redirection = 0;
	}
	while (++i <= SIZE)
	{
		if (buf[i] == '\n')
		{
			g_redirection = 1;
			return ;
		}
	}
	g_redirection = 0;
}

int		ft_read_stdin(void)
{
	int			i;
	int			rn;
	int			temp;
	char		buf_res[SIZE];
	char		buf[SIZE];

	i = -1;
	ft_init_str(buf_res, buf, SIZE);
	rn = read(0, buf, SIZE);
	if (rn < 5)
		return (0);
	ft_strcat(buf_res, buf);
	ft_check_redirection(buf);
	buf[rn - 4] = '\0';
	temp = ft_atoi(buf);
	ft_init_str(buf, buf, SIZE);
	while (++i < temp && (rn = read(0, buf, SIZE)))
		ft_strcat(buf_res, buf);
	if (g_redirection == 0)
		ft_putstr("\n");
	fill_temp(buf_res);
	return (1);
}
