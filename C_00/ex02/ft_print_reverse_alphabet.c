/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:11:49 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/22 20:35:04 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	show_letter;
	char	end_letter;

	show_letter = 'z';
	end_letter = 'a';
	while (show_letter >= end_letter)
	{
		write(1, &show_letter, 1);
		show_letter--;
	}
}
