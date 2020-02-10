/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:35:45 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/22 21:14:40 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	first_letter;
	char	last_letter;

	first_letter = 'a';
	last_letter = 'z';
	while (first_letter <= last_letter)
	{
		write(1, &first_letter, 1);
		first_letter++;
	}
}
