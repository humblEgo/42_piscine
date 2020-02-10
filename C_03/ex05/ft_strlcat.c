/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:27:42 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/29 11:36:48 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	import_len(char *str)
{
	unsigned int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int src_len;
	unsigned int dest_len;
	unsigned int idx;

	idx = 0;
	src_len = import_len(src);
	dest_len = import_len(dest);
	if (size < dest_len)
		return (src_len + size);
	else
	{
		while (idx + dest_len + 1 < size && src[idx] != '\0')
		{
			dest[dest_len + idx] = src[idx];
			idx++;
		}
		dest[dest_len + idx] = '\0';
		return (src_len + dest_len);
	}
}
