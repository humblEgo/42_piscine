/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:44:34 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/29 11:08:23 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		idx;

	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx] && s2[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}