/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:10:45 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/12 09:46:15 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_puterror(int err_num, char *path, char *pname)
{
	ft_putstr_err(basename(pname));
	write(2, ": ", 2);
	ft_putstr_err(path);
	write(2, ": ", 2);
	ft_putstr_err(strerror(err_num));
	write(2, "\n", 1);
}
