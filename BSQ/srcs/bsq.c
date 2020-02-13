/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:59:30 by sanam             #+#    #+#             */
/*   Updated: 2020/02/12 22:16:48 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_min(int r, int c)
{
	int min;

	min = g_map[r - 1][c - 1];
	if (min > g_map[r][c - 1])
		min = g_map[r][c - 1];
	if (min > g_map[r - 1][c])
		min = g_map[r - 1][c];
	g_map[r][c] = min + 1;
}

void	bsq(t_map_info *minfo)
{
	int		r;
	int		c;

	r = 1;
	c = 1;
	while (r < minfo->row)
	{
		c = 1;
		while (c < minfo->col)
		{
			if (g_map[r][c] != 0)
				ft_min(r, c);
			c++;
		}
		r++;
	}
}

t_pos	*ft_get_pos(t_map_info *minfo)
{
	int		r;
	int		c;
	int		max;
	t_pos	*pos;

	bsq(minfo);
	r = -1;
	max = 0;
	if (!(pos = malloc(sizeof(t_pos))))
		return (0);
	while (++r < minfo->row)
	{
		c = -1;
		while (++c < minfo->col)
		{
			if (g_map[r][c] > max)
			{
				max = g_map[r][c];
				pos->r = r - max + 1;
				pos->c = c - max + 1;
				pos->size = max;
			}
		}
	}
	return (pos);
}

void	ft_print_answer(t_map_info *minfo)
{
	int		r;
	int		c;
	t_pos	*pos;

	pos = ft_get_pos(minfo);
	r = -1;
	while (++r < minfo->row)
	{
		c = -1;
		while (++c < minfo->col)
		{
			if (r >= pos->r && r < (pos->r + pos->size) &&
				c >= pos->c && c < (pos->c + pos->size))
				ft_putchar(minfo->full);
			else if (g_map[r][c] == 0)
				ft_putchar(minfo->obs);
			else
				ft_putchar(minfo->empty);
		}
		ft_putchar('\n');
	}
	free(pos);
	ft_free(minfo);
}
