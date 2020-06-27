/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:49:05 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:08:48 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int find;

	i = 0;
	j = 0;
	while (needle[j])
		j++;
	find = j;
	j = 0;
	if (find == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (j == find - 1)
				return ((char *)haystack + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
