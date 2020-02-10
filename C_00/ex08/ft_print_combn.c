/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 09:43:04 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/23 16:48:40 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(int i)
{
	char	ascii_num;

	ascii_num = '0' + i;
	write(1, &ascii_num, 1);
}

void	output_printer(int output_array[9], int dest_idx)
{
	int idx;

	idx = 0;
	while (idx < dest_idx)
	{
		print_char(output_array[idx]);
		idx++;
	}
	if (output_array[dest_idx] != 9 && output_array[0] != (10 - dest_idx))
	{
		write(1, ", ", 2);
	}
}

void	print_combn(int sta_num, int cur_idx, int dest_idx, int output_arr[9])
{
	int value_num;

	value_num = sta_num;
	if (cur_idx == dest_idx)
	{
		output_printer(output_arr, dest_idx);
		return ;
	}
	while (value_num < 10)
	{
		output_arr[cur_idx] = value_num;
		print_combn(value_num + 1, cur_idx + 1, dest_idx, output_arr);
		value_num++;
	}
}

void	ft_print_combn(int n)
{
	int output_array[9];

	print_combn(0, 0, n, output_array);
}
