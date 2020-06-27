/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:28:01 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:04:39 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t find;

	i = 0;
	j = 0;
	while (needle[j])
		j++;
	find = j;
	j = 0;
	if (find == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
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
