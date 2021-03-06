/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstr_is_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:42:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/26 12:24:49 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ('A' <= str[idx] && str[idx] <= 'Z')
		{
			idx++;
			continue;
		}
		else if ('a' <= str[idx] && str[idx] <= 'z')
		{
			str[idx] -= 32;
		}
		idx++;
	}
	return (str);
}
