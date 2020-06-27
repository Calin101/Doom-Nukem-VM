/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:50:06 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:02:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
	{
		if (fd > 2 && fd < 0)
			return ;
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}
