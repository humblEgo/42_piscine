/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:46:32 by sanam             #+#    #+#             */
/*   Updated: 2020/02/12 22:45:36 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_put_map_error(int i)
{
	if (i == 1 || i == 0)
		ft_putstr("map error\n");
	else
		ft_putstr("\nmap error\n");
}

int		main(int argc, char **argv)
{
	t_map_info	*minfo;
	int			i;

	i = (argc == 1) ? -1 : 0;
	while (++i < argc)
	{
		if (argc == 1 && (!(ft_read_stdin())))
			return (ft_putstr_err("map error\n"));
		if (!((argc == 1) ? ft_is_valid_map("temp") : ft_is_valid_map(argv[i])))
		{
			ft_put_map_error(i);
			continue ;
		}
		minfo = (argc == 1) ? ft_get_map_info("temp") :
			ft_get_map_info(argv[i]);
		(argc == 1) ? ft_read_map(minfo, "temp") :
			ft_read_map(minfo, argv[i]);
		if (i > 1)
			ft_putchar('\n');
		ft_print_answer(minfo);
	}
	return (0);
}
