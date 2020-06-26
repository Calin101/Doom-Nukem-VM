/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:46:05 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 15:46:29 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	clear_im(t_input *data)
{
	int i;

	i = -1;
	while (++i < data->screensize)
	{
		data->rays[i].dp1 = 0;
		data->rays[i].dp2 = 0;
		data->rays[i].distcolli = -1;
	}
}

void	rea_ray(t_input *data)
{
	int i;

	i = -1;
	while (++i < data->screensize)
		data->rays[i].distcolli = -1;
}
