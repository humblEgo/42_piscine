/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:01:35 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/23 13:53:45 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(int i)
{
	char	ascii_num;

	ascii_num = '0' + i;
	write(1, &ascii_num, 1);
}

void	print_integer(int input_num)
{
	int	ten_digit_num;
	int	one_digit_num;

	ten_digit_num = input_num / 10;
	one_digit_num = input_num % 10;
	print_char(ten_digit_num);
	print_char(one_digit_num);
}

void	ft_print_comb2(void)
{
	int	first_num;
	int	second_num;

	first_num = 0;
	second_num = 0;
	while (first_num <= 98)
	{
		second_num = first_num + 1;
		while (second_num <= 99)
		{
			print_integer(first_num);
			write(1, " ", 1);
			print_integer(second_num);
			if (first_num != 98)
			{
				write(1, ", ", 2);
			}
			second_num++;
		}
		first_num++;
	}
}
