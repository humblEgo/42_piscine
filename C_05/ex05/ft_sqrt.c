/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:00:09 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/30 11:08:42 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long int sqrt_num;
	long long int temp_nb;

	sqrt_num = 1;
	temp_nb = (long long int)nb;
	while (sqrt_num * sqrt_num < temp_nb)
	{
		sqrt_num++;
	}
	if (sqrt_num * sqrt_num == temp_nb)
		return ((int)sqrt_num);
	return (0);
}
