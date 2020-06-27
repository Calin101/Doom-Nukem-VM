/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:52:45 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:04:17 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && (j < n))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}
