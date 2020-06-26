/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:58:08 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/26 18:29:51 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	redefine_in_thread(t_input *data, t_poly *poly, int i, int dy)
{
	data->thread_tab[i].poly = poly;
	data->thread_tab[i].box.amin.x = poly->box.amin.x;
	data->thread_tab[i].box.amax.x = poly->box.amax.x;
	data->thread_tab[i].box.amin.y = (float)(i / (float)NB_THREAD) *
	dy + poly->box.amin.y;
	data->thread_tab[i].box.amax.y = (float)((i + 1) /
	(float)NB_THREAD) * dy + poly->box.amin.y;
	data->thread_tab[i].inputs = data;
}

void	thread_start(t_input *data, t_poly *poly)
{
	int i;
	int dx;
	int dy;

	while (poly)
	{
		if (poly->isvisible)
		{
			i = -1;
			dx = poly->box.amax.x - poly->box.amin.x;
			dy = poly->box.amax.y - poly->box.amin.y;
			while (++i < NB_THREAD)
			{
				redefine_in_thread(data, poly, i, dy);
				pthread_create(&data->thread_tab[i].thread, NULL,
				&ray_boxes, &data->thread_tab[i]);
			}
			i = -1;
			while (++i < NB_THREAD)
				pthread_join(data->thread_tab[i].thread, NULL);
		}
		poly = poly->next;
	}
}
