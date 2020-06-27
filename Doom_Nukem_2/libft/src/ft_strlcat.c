/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:44:05 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:04:05 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(dst) + ft_strlen((char *)src);
	if (size <= ft_strlen(dst))
		return (ft_strlen((char *)src) + size);
	while (*dst)
		dst++;
	while ((i < size - (len - ft_strlen((char *)src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
