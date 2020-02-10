/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstr_is_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:42:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/27 12:26:45 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int idx;
	int return_value;

	idx = 0;
	return_value = 1;
	while (str[idx] != '\0')
	{
		if ('a' <= str[idx] && str[idx] <= 'z')
		{
			return_value = 1;
		}
		else
		{
			return (0);
		}
		idx++;
	}
	return (return_value);
}
