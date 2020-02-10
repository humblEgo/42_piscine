/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:31:59 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/28 11:50:33 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int dest_length;
	unsigned int src_idx;

	src_idx = 0;
	dest_length = 0;
	while (dest[dest_length])
	{
		dest_length++;
	}
	while (src[src_idx] && src_idx < nb)
	{
		dest[dest_length + src_idx] = src[src_idx];
		src_idx++;
	}
	dest[dest_length + src_idx] = '\0';
	return (dest);
}
