/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:25:48 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/28 09:16:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char *chr, int digit)
{
	int			decimal_num;
	char		*hex_alpha;

	decimal_num = (int)*chr;
	hex_alpha = "0123456789abcdef";
	if (decimal_num == 40)
	{
		return ;
	}
	if (digit == 2)
	{
		write(1, &hex_alpha[decimal_num / 16], 1);
	}
	write(1, &hex_alpha[decimal_num % 16], 1);
}

void	import_hex_digit(long long addr_long, char *addr_chr, int size)
{
	if (addr_long > 16)
	{
		import_hex_digit(addr_long / 16, addr_chr, size - 1);
	}
	addr_chr[size - 1] = addr_long % 16;
}

void	print_address(void *addr)
{
	long long	addr_long;
	char		addr_chr[16];
	int			idx;

	addr_long = (long long)addr;
	import_hex_digit(addr_long, addr_chr, 16);
	idx = 0;
	while (idx < 16)
	{
		if (addr_chr[idx] >= 16)
		{
			print_hex(&addr_chr[idx], 2);
		}
		else
		{
			print_hex(&addr_chr[idx], 1);
		}
		idx++;
	}
}

void	print_value(char *str, int idx, int flag)
{
	if (flag == 1)
	{
		if (idx % 2 == 0)
		{
			write(1, " ", 1);
		}
		print_hex(&str[idx], 2);
	}
	else
	{
		if (!(32 <= str[idx] && str[idx] <= 126))
		{
			write(1, ".", 1);
		}
		else
		{
			write(1, &str[idx], 1);
		}
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	idx;
	char			*str;

	str = (char *)addr;
	idx = 0;
	print_address(addr);
	write(1, ":", 1);
	while (idx < size)
	{
		print_value(str, idx, 1);
		idx++;
	}
	write(1, " ", 1);
	idx = 0;
	while (idx < size)
	{
		print_value(str, idx, 2);
		idx++;
	}
	write(1, "\n", 1);
	return (addr);
}
