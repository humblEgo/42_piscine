/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:09:46 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/01 12:01:05 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int div;
	unsigned int nb_us;

	if (nb <= 1)
		return (0);
	else if (nb == 2 || nb == 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	nb_us = (unsigned int)nb;
	div = 5;
	while (div * div <= nb_us)
	{
		if (nb_us % div == 0)
			return (0);
		div += 2;
	}
	return (1);
}
