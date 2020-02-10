/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:31:59 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/29 11:31:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int dest_length;
	int src_idx;

	src_idx = 0;
	dest_length = 0;
	while (dest[dest_length])
	{
		dest_length++;
	}
	while (src[src_idx])
	{
		dest[dest_length + src_idx] = src[src_idx];
		src_idx++;
	}
	dest[dest_length + src_idx] = '\0';
	return (dest);
}
