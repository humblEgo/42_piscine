/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:00:54 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/30 18:52:31 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int idx;

	idx = 0;
	while (argv[0][idx] && argc)
	{
		putchar(argv[0][idx]);
		idx++;
	}
	putchar('\n');
	return (0);
}
