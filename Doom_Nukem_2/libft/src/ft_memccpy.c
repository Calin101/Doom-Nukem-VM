/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:17:02 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:01:13 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;

	i = 0;
	tmp_src = (unsigned char *)src;
	tmp_dest = (unsigned char *)dst;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_src[i] == (unsigned char)c)
			return ((unsigned char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
