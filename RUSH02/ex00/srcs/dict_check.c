/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:45:17 by kycho             #+#    #+#             */
/*   Updated: 2020/02/11 12:48:02 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"


void	puterror(void)
{
	write(1, "Dict Error\n", 11);
}

int		check_dict_oneline(char *dict, int idx)
{
	if (dict[idx] == '0')
		if (dict[idx + 1] != ' ' && dict[idx + 1] != ':')
			return (0);
	if (dict[idx] < '0' || '9' < dict[idx])
		return (0);
	while ('0' <= dict[idx] && dict[idx] <= '9')
		idx++;
	while (dict[idx] == ' ')
		idx++;
	if (dict[idx] != ':')
		return (0);
	idx++;
	while (dict[idx] == ' ')
		idx++;
	if (!(33 <= dict[idx] && dict[idx] <= 126))
		return (0);
	while (33 <= dict[idx] && dict[idx] <= 126)
		idx++;
	if (dict[idx] != '\n' && dict[idx] != '\0')
		return (0);
	return (idx);
}

int		check_dict(char *dict)
{
	int i;

	i = 0;
	while (dict[i] == '\n')
		i++;
	if (dict[i] == '\0')
	{
		puterror();
		return (0);
	}
	i--;
	while (dict[i] != '\0')
	{
		i = check_dict_oneline(dict, i + 1);
		if (dict[i] != '\n' && dict[i] != '\0')
		{
			puterror();
			return (0);
		}
		if (i == 0)
		{
			puterror();
			return (0);
		}
	}
	return (1);
}

int		check_repit_key(t_dic *arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i].key[0] != '\0')
	{
		j = 0;
		while (arr[j].key[0] != '\0')
		{
			if (i != j && ft_strcmp(arr[i].key, arr[j].key) == 0)
			{
				puterror();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
