/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:53:07 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:53:08 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static double		percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int					get_color(t_file *file, t_bresenham brese,
					int start, int end)
{
	double percentage;

	if (file->color.current == end)
		return (1);
	if (brese.dx > brese.dy)
		percentage = percent(file->point.xi, file->point.xf, brese.x);
	else
		percentage = percent(file->point.yi, file->point.yf, brese.y);
	file->color.red = get_light((start >> 16) & 0xFF, (end >> 16) &
			0xFF, percentage);
	file->color.green = get_light((start >> 8) & 0xFF, (end >> 8) &
			0xFF, percentage);
	file->color.blue = get_light(start & 0xFF, end & 0xFF, percentage);
	return (1);
}
