/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:45:14 by sanam             #+#    #+#             */
/*   Updated: 2020/02/12 22:17:47 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_malloc_map(t_map_info *minfo)
{
	int		r;

	r = 0;
	if (!(g_map = (int **)malloc(sizeof(int *) * minfo->row)))
		return ;
	while (r < minfo->row)
	{
		if (!(g_map[r] = (int *)malloc(sizeof(int) * minfo->col)))
			return ;
		r++;
	}
}

void	ft_free(t_map_info *minfo)
{
	int		r;

	r = -1;
	while (++r < minfo->row)
		free(g_map[r]);
	free(g_map);
	free(minfo);
}
