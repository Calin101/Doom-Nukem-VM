/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:25:52 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:01:30 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*tmp_dest;
	const char	*tmp_src;

	i = -1;
	tmp_src = src;
	tmp_dest = dest;
	if (tmp_src < tmp_dest)
		while ((int)(--len) >= 0)
			*(tmp_dest + len) = *(tmp_src + len);
	else
		while (++i < len)
			*(tmp_dest + i) = *(tmp_src + i);
	return (dest);
}
