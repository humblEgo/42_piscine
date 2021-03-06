/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstr_is_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:42:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/26 12:26:46 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ('a' <= str[idx] && str[idx] <= 'z')
		{
			idx++;
			continue;
		}
		else if ('A' <= str[idx] && str[idx] <= 'Z')
		{
			str[idx] += 32;
		}
		idx++;
	}
	return (str);
}
