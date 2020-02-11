/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:55:38 by kycho             #+#    #+#             */
/*   Updated: 2020/02/09 16:55:42 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int g_order ;

typedef struct	t_dic
{
	char *key;
	char *value;
}				t_dic;

int		ft_strlen(char *str);

void	cvrt_print_str(char *str, t_dic *arr, int str_len, int spliter);

char	*ft_strcpy(char *dest, char *src);
*/

int g_order = 0;

void	set_t_dic(t_dic *arr)
{
	arr[0].key = "0"; 
	arr[0].value = "zero";
	arr[1].key = "1"; 
	arr[1].value = "one";
	arr[2].key = "2"; 
	arr[2].value = "two";
	arr[3].key = "3"; 
	arr[3].value = "three";
	arr[4].key = "4";
	arr[4].value = "four";
	arr[5].key = "5"; 
	arr[5].value = "five";
	arr[6].key = "6"; 
	arr[6].value = "six";
	arr[7].key = "7"; 
	arr[7].value = "seven";
	arr[8].key = "8"; 
	arr[8].value = "eight";
	arr[9].key = "9";
	arr[9].value = "nine";
	arr[10].key = "10"; 
	arr[10].value = "ten";
	arr[11].key = "11"; 
	arr[11].value = "eleven";
	arr[12].key = "12"; 
	arr[12].value = "twelve";
	arr[13].key = "13"; 
	arr[13].value = "thirteen";
	arr[14].key = "14"; 
	arr[14].value = "fourteen";
	arr[15].key = "15"; 
	arr[15].value = "fifteen";
	arr[16].key = "16"; 
	arr[16].value = "sixteen";
	arr[17].key = "17"; 
	arr[17].value = "seventeen";
	arr[18].key = "18"; 
	arr[18].value = "eighteen";
	arr[19].key = "19"; 
	arr[19].value = "nineteen";
	arr[20].key = "20"; 
	arr[20].value = "twenty";
	arr[21].key = "30"; 
	arr[21].value = "thirty";
	arr[22].key = "40"; 
	arr[22].value = "forty";
	arr[23].key = "50";
	arr[23].value = "fifty";
	arr[24].key = "60"; 
	arr[24].value = "sixty";
	arr[25].key = "70"; 
	arr[25].value = "seventy";
	arr[26].key = "80"; 
	arr[26].value = "eighty";

	arr[27].key = "90"; 
	arr[27].value = "ninety";

	arr[28].key = "100"; 
	arr[28].value = "hundred";

	arr[29].key = "1000"; 
	arr[29].value = "thousand";

	arr[30].key = "1000000"; 
	arr[30].value = "million";
	arr[31].key = "1000000000"; 
	arr[31].value = "billion";
	arr[32].key = "1000000000000"; 
	arr[32].value = "trillion";
	arr[33].key = "1000000000000000"; 
	arr[33].value = "quadrillion";
	arr[34].key = "1000000000000000000"; 
	arr[34].value = "quintillion";
	arr[35].key = "1000000000000000000000"; 
	arr[35].value = "sextillion";
	arr[36].key = "1000000000000000000000000"; 
	arr[36].value = "septillion";
	arr[37].key = "1000000000000000000000000000"; 
	arr[37].value = "octillion";
	arr[38].key = "1000000000000000000000000000000"; 
	arr[38].value = "nonillion";
	arr[39].key = "1000000000000000000000000000000000"; 
	arr[39].value = "decillion";
	arr[40].key = "1000000000000000000000000000000000000"; 
	arr[40].value = "undecillion";
	arr[41].key = 0;
	arr[41].value = 0;
}

char *remove_front_zero(char *str)
{
	int i;
	char *new_str;

	i = 0;
	while (str[i] == '0')
		i++;
	new_str = malloc(getlen(str + i) + 1);
	new_str = ft_strcpy(new_str, str+i);
	return (new_str);
}

int	main(int argc, char**argv)
{
	char *str_origin;
	char *str;
	t_dic *arr;
	int spliter;

	arr = (t_dic *)malloc(sizeof(t_dic) * (43));
	set_t_dic(arr);
	
	str_origin = argv[1];
//	str = remove_front_zero(str_origin);

	//printf("%s\n", str);

	spliter = 0;
	srch_str(str_origin, arr, getlen(str_origin), spliter);
	free(arr);
	free(str);
	return (0);
}
