/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:58:50 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/10 21:53:32 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdio.h>

void	stdin_read(int fd, char *tail_num);
int		print_filename(char *arg, int argc, int newline_flag);
void	ft_put_open_error(char *arg, char *pname, int err_num, int order);
void	ft_put_argu_error(char *arg, char *pname);
void	ft_put_offset_error(char *arg, char *pname);
void	ft_putstr(char *str);
int		ft_strcmp(char *a, char *b);
int		ft_atoi(char *str);
int		ft_is_num(char *num_str);
int		is_valid_opt(char *option);
int		ft_is_dir(char *target);
#endif
