/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:59:19 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/25 20:31:22 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div_quotient;
	int div_remainder;

	div_quotient = (*a) / (*b);
	div_remainder = (*a) % (*b);
	*a = div_quotient;
	*b = div_remainder;
}
