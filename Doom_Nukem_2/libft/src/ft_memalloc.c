/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:11:06 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:01:11 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void *tab;

	tab = (void *)malloc(sizeof(void *) * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
