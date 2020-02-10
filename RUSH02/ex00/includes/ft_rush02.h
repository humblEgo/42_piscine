/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:16:51 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/09 23:42:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_dict
{
	char	key[1024];
	char	value[1024];
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
int				only_one_zeros_and_not_ten(char *str, t_dic *arr);

void			create_dict_buf(char *str, int fd, int str_len);
int				check_mem_alloc(char *buf);
t_dic			*parse_dict(char *dict, int line_cnt);
char			*new_parse_dict(char *dict);
int				remove_space_len(char *dict);
void			find_key(char *ptr, char sep, t_dic *t_dic_array);
char			*find_value(char *ptr, char sep, t_dic *t_dic_array);
void			ft_memset(char *buf, int len);

int				srch_str(char *str, t_dic *arr, int str_len, int spliter);
int				check_repit_key(t_dic *arr);
int				check_dict(char *dict);
#endif
