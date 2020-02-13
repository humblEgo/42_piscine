/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:53:58 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/07 11:27:48 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	put_error(int error_num)
{
	if (error_num == 0)
		write(1, "Stop : division by zero", 23);
	else if (error_num == 1)
		write(1, "Stop : modulo by zero", 21);
	else if (error_num == 2)
		write(1, "0", 1);
	write(1, "\n", 1);
}

void	put_cal(int a, int b, int flag)
{
	int res;

	if (flag == 0)
		res = a + b;
	if (flag == 1)
		res = a - b;
	if (flag == 2)
		res = a * b;
	if (flag == 3)
		res = a / b;
	if (flag == 4)
		res = a % b;
	ft_putnbr(res);
	write(1, "\n", 1);
}

int		check_operator(char *arr)
{
	int		i;
	char	*oper;

	oper = "+-*/%";
	i = 0;
	while (arr[i])
		i++;
	if (i != 1)
		return (-1);
	i = -1;
	while (oper[++i])
		if (oper[i] == *arr)
			break ;
	if (i == 5)
		return (-1);
	return (i);
}

void	cal(int a, int b, char *arr)
{
	char	*oper;
	int		idx_oper;

	oper = "+-*/%";
	idx_oper = check_operator(arr);
	if (idx_oper == -1)
		put_error(2);
	else
	{
		if (oper[idx_oper] == '/' && b == 0)
			put_error(0);
		else if (oper[idx_oper] == '%' && b == 0)
			put_error(1);
		else
			put_cal(a, b, idx_oper);
	}
}

int		main(int argc, char **argv)
{
	int	left_num;
	int	right_num;

	if (argc != 4)
		return (0);
	else
	{
		left_num = ft_atoi(argv[1]);
		right_num = ft_atoi(argv[3]);
		cal(left_num, right_num, argv[2]);
	}
	return (0);
}
