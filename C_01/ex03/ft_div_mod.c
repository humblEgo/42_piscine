/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:23:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/25 20:31:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int div_quotient;
	int div_remainder;

	div_quotient = a / b;
	div_remainder = a % b;
	*div = div_quotient;
	*mod = div_remainder;
}
