/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:25:48 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/27 22:45:56 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_by_hex(unsigned char *chr)
{
	char			*hex_alpha;
	unsigned int	decimal_num;

	hex_alpha = "0123456789abcdef";
	decimal_num = *chr;
	write(1, &hex_alpha[decimal_num / 16], 1);
	write(1, &hex_alpha[decimal_num % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				idx;
	unsigned char	*work_str;

	work_str = (unsigned char*)str;
	idx = 0;
	while (work_str[idx] != '\0')
	{
		if (!(32 <= work_str[idx] && work_str[idx] <= 126))
		{
			write(1, "\\", 1);
			print_by_hex(&work_str[idx]);
		}
		else
		{
			write(1, &work_str[idx], 1);
		}
		idx++;
	}
}
