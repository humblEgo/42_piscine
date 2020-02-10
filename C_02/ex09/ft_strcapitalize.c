/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstr_is_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:42:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/01/27 23:04:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	*make_upper(unsigned char *chr)
{
	if ('a' <= *chr && *chr <= 'z')
	{
		*chr -= 32;
	}
	return (chr);
}

unsigned char	*make_lower(unsigned char *chr)
{
	if ('A' <= *chr && *chr <= 'Z')
	{
		*chr += 32;
	}
	return (chr);
}

void			edit_to_capital(unsigned char *str, int idx, int *capit_flag)
{
	if ('a' <= str[idx] && str[idx] <= 'z')
	{
		make_upper(&str[idx]);
	}
	else if (('A' <= str[idx] && str[idx] <= 'Z') ||
			('0' <= str[idx] && str[idx] <= '9'))
	{
	}
	else
	{
		*capit_flag = 1;
		return ;
	}
	*capit_flag = 0;
}

void			edit_to_lower(unsigned char *str, int idx, int *capit_flag)
{
	if ('A' <= str[idx] && str[idx] <= 'Z')
	{
		make_lower(&str[idx]);
		*capit_flag = 0;
	}
	else if (('a' <= str[idx] && str[idx] <= 'z') ||
			('0' <= str[idx] && str[idx] <= '9'))
	{
		*capit_flag = 0;
	}
	else
	{
		*capit_flag = 1;
	}
}

char			*ft_strcapitalize(char *str)
{
	int				idx;
	int				*capit_flag;
	unsigned char	*work_str;
	int				num;

	num = 1;
	work_str = (unsigned char *)str;
	idx = 0;
	capit_flag = &num;
	while (work_str[idx] != '\0')
	{
		if (*capit_flag == 1)
		{
			edit_to_capital(work_str, idx, capit_flag);
		}
		else
		{
			edit_to_lower(work_str, idx, capit_flag);
		}
		idx++;
	}
	str = (char *)work_str;
	return (str);
}
