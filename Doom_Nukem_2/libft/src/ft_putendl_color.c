/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:26:10 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:01:46 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl_color(const char *s, const char *color)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putendl("\e[39;49m");
}
