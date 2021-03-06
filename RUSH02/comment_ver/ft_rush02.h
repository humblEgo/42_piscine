/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:16:51 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 17:20:33 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_dict
{
	char	*key;
	char	*value;
}				t_dic;

int				g_order;

void			ft_putstr(char *str);
int				ft_strcmp(char *a, char *b);
int				getlen(char *str);
char			*ft_strcpy(char *dest, char *src);
void			put_value(char *str, t_dic *arr);
int				is_key(char *key, t_dic *arr);
char			*split_digit(int	splilter, int str_len);
char			*split_right(int	spliter, char *str, int str_len);
char			*split_left(int		spliter, char *str);
int				srch_str(char *str, t_dic *arr, int str_len, int spliter);
int				go_free(char *a, char *b, char *c, char *d);
char			*tail_add_zero(char *str, int size);
int				check_print_value(char *str, t_dic *arr);
#endif
