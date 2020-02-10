/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstr_is_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:42:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/26 12:16:31 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int idx;
	int return_value;

	return_value = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if ('A' <= str[idx] && str[idx] <= 'Z')
		{
			return_value = 1;
		}
		else if ('a' <= str[idx] && str[idx] <= 'z')
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
