/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:10:45 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/10 20:17:08 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterror(int err_num, char *path, char *pname)
{
	ft_putstr(basename(pname));
	write(1, ": ", 2);
	ft_putstr(path);
	write(1, ": ", 2);
	ft_putstr(strerror(err_num));
	write(1, "\n", 1);
}
