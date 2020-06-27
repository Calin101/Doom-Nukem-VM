/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:45 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:49:09 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void		color_converter(t_file *file, int hex)
{
	file->color.red = ((hex >> 16) & 0xFF);
	file->color.green = ((hex >> 8) & 0xFF);
	file->color.blue = ((hex) & 0xFF);
}

void			color_pixel(t_file *file, int x, int y)
{
	int i;

	i = (x * 4) + (y * (file->s_l));
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		file->my_str_img[i] = (char)file->color.blue;
		file->my_str_img[i + 1] = (char)file->color.green;
		file->my_str_img[i + 2] = (char)file->color.red;
	}
}

static void		brese_x(t_bresenham brese, t_file *file)
{
	brese.cumul = brese.dx / 2;
	while (brese.i <= brese.dx)
	{
		brese.x += brese.xinc;
		brese.cumul += brese.dy;
		if (brese.cumul >= brese.dx)
		{
			brese.cumul -= brese.dx;
			brese.y += brese.yinc;
		}
		color_converter(file, file->color.start);
		color_pixel(file, (double)brese.x, (double)brese.y);
		brese.i++;
	}
}

static void		brese_y(t_bresenham brese, t_file *file)
{
	brese.cumul = brese.dy / 2;
	while (brese.i <= brese.dy)
	{
		brese.y += brese.yinc;
		brese.cumul += brese.dx;
		if (brese.cumul >= brese.dy)
		{
			brese.cumul -= brese.dy;
			brese.x += brese.xinc;
		}
		color_converter(file, file->color.start);
		color_pixel(file, (double)brese.x, (double)brese.y);
		brese.i++;
	}
}

void			bresenham(t_file *file, t_dot a, t_dot b)
{
	t_bresenham brese;

	brese.i = 1;
	brese.x = a.x;
	brese.y = a.y;
	brese.dx = b.x - a.x;
	brese.dy = b.y - a.y;
	brese.xinc = (brese.dx > 0) ? 1 : -1;
	brese.yinc = (brese.dy > 0) ? 1 : -1;
	brese.dx = fabs(brese.dx);
	brese.dy = fabs(brese.dy);
	color_pixel(file, brese.x, brese.y);
	if (brese.dx > brese.dy)
		brese_x(brese, file);
	else
		brese_y(brese, file);
}
