/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:25:48 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/10 15:26:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

# define MAX 30000

void	ft_putstr(char *str);
void	ft_puterror(int err_num, char *path, char *pname);
#endif
