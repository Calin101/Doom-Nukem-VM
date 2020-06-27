/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:01:08 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:08:42 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	str_temp;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (j > i)
	{
		str_temp = str[j];
		str[j] = str[i];
		str[i] = str_temp;
		i++;
		j--;
	}
	return (str);
}
