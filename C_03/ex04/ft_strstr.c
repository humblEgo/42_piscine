/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:42:40 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/28 18:47:36 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int idx;
	int cmp_idx;

	if (!(*to_find))
	{
		return (str);
	}
	idx = 0;
	while (str[idx])
	{
		cmp_idx = 0;
		if (str[idx] == to_find[cmp_idx])
		{
			while (str[idx + cmp_idx] == to_find[cmp_idx] && to_find[cmp_idx])
			{
				cmp_idx++;
			}
			if (to_find[cmp_idx] == '\0')
			{
				return (&str[idx]);
			}
		}
		idx++;
	}
	return (0);
}
