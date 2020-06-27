/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:43:18 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:04:36 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (!(s = (char *)malloc(size + 1)))
		return (s);
	ft_bzero(s, size + 1);
	return (s);
}
