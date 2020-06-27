/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:48:20 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:02:13 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_color(const char *s, const char *color)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr("\e[39;49m");
}
