/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:57:55 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/31 10:28:15 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int *board, int *count)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = (board[i] + '0');
		write(1, &c, 1);
		i++;
	}
	*count += 1;
	write(1, "\n", 1);
}

int		abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

int		check_able(int col, int row, int *board)
{
	int be_col;

	be_col = 0;
	while (be_col < col)
	{
		if (board[be_col] == row ||
			abs(board[be_col] - row) == abs(be_col - col))
			return (0);
		be_col++;
	}
	return (1);
}

void	set_queens(int col, int *board, int *count)
{
	int row;

	row = 0;
	if (col == 10)
	{
		print_board(board, count);
		return ;
	}
	else
	{
		while (row < 10)
		{
			if (check_able(col, row, board))
			{
				board[col] = row;
				set_queens(col + 1, board, count);
			}
			row++;
		}
	}
	return ;
}

int		ft_ten_queens_puzzle(void)
{
	int count;
	int board[10];

	count = 0;
	set_queens(0, board, &count);
	return (count);
}
