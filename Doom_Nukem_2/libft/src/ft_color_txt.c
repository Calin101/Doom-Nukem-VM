/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:22:39 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:00:14 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*color_txt(char *str, char *name, char *color)
{
	ft_strcat(str, color);
	ft_strcat(str, name);
	ft_strcat(str, "\e[39;49m");
	return (str);
}
