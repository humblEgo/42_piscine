/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:54:00 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/28 18:11:04 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;
	char			*start;

	start = dest;
	idx = 0;
	if (n)
	{
		while (idx < n)
		{
			if (src[idx] == '\0')
			{
				while (idx < n)
				{
					start[idx] = '\0';
					idx++;
				}
				return (start);
			}
			start[idx] = src[idx];
			idx++;
		}
	}
	return (start);
}
