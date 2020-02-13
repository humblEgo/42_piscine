/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:57:09 by hna               #+#    #+#             */
/*   Updated: 2020/02/12 23:48:23 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define SIZE 3000000

/*
**				Global Variables
*/

int				**g_map;
int				g_redirection;
/*
**				struct for map info
*/

typedef struct	s_map_info
{
	char		empty;
	char		obs;
	char		full;
	int			row;
	int			col;
}				t_map_info;

/*
** 				struct for output map
*/

typedef struct	s_pose
{
	int			r;
	int			c;
	int			size;
}				t_pos;

/*
**				Basic print
*/

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int num);
int				ft_putstr_err(char *str);

/*
**				Basic utility
*/

char			*ft_strcat(char *dest, char *src);
int				ft_atoi(char *str);
int				ft_natoi(char *str, int n);
int				ft_strlen(char *src);

/*
**				Read Map
*/

void			ft_read_first_line(char *fpath, t_map_info *minfo);
void			ft_put_data(char *buf, t_map_info *minfo);
void			ft_read_map(t_map_info *minfo, char *fpath);
int				ft_get_filesize(char *fpath);
t_map_info		*ft_get_map_info(char *fpath);

/*
**				Read Map Stdin
*/

void			ft_init_str(char *str1, char *str2, int size);
void			ft_fill_temp(char *buf_res);
int				ft_read_stdin(void);

/*
**				BSQ
*/

void			bsq(t_map_info *minfo);
void			ft_min(int r, int c);
void			ft_print_answer(t_map_info *minfo);
t_pos			*ft_get_pos(t_map_info *minfo);

/*
**				valid check1
*/

int				ft_is_valid_map_marks(char *mark_addr, char *ascii);
int				ft_is_valid_lines_num(char *map_buf,
				int line_len, int *atoied_num);
int				ft_is_valid_chars(char *map_buf, char *ascii);
int				ft_is_valid_cols_rows(char *map_addr, int *atoied_num);
int				ft_is_valid_map_buf(char *map_buf);

/*
**				valid check2
*/

int				ft_is_valid_map(char *map);
int				ft_get_map_filesize(char *map);
int				ft_get_line_len(char *line_strt_addr);
void			ft_cpy_map_to_buf(char *map_buf, char *map, int map_fsize);

/*
**				Malloc & Free
*/

void			ft_malloc_map(t_map_info *minfo);
void			ft_free(t_map_info *minfo);

#endif
