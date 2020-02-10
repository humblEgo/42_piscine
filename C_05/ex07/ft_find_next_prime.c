/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:34:02 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/01 12:05:12 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(unsigned int nb)
{
	unsigned int	div;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	div = 5;
	while (div * div <= nb)
	{
		if (nb % div == 0)
			return (0);
		div += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	unsigned int nb_us;

	if (nb <= 2)
		return (2);
	nb_us = (unsigned int)nb;
	if (nb_us % 2 == 0)
		nb_us += 1;
	while (!is_prime(nb_us))
	{
		nb_us = nb_us + 2;
	}
	return ((int)nb_us);
}
