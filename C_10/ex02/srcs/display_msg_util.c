/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:49:36 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/12 18:41:37 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

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
	ft_putstr_err(basename(pname));
	ft_putstr_err(": ");
	ft_putstr_err(arg);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(err_num));
	if (order != 3)
		ft_putstr("\n");
}

void	ft_put_offset_error(char *arg, char *pname)
{
	char *line1;

	line1 = ": illegal offset -- ";
	ft_putstr_err(basename(pname));
	ft_putstr_err(line1);
	ft_putstr_err(arg);
	ft_putstr_err("\n");
}

void	ft_put_argu_error(char *arg, char *pname)
{
	char *line1;
	char *line2;

	line1 = ": option requires an argument -- ";
	line2 = "usage: tail [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]";
	ft_putstr_err(basename(pname));
	ft_putstr_err(line1);
	ft_putstr_err(&arg[1]);
	ft_putstr_err("\n");
	ft_putstr_err(line2);
	ft_putstr_err("\n");
}
