/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:48:06 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/26 18:29:16 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	print_line(t_input *input, t_dot a, t_dot b, int color)
{
	float	dx;
	float	dy;
	int		tall;
	int		i;

	i = 0;
	if (b.x == a.x && b.y == a.y)
		return ;
	tall = tallnomin(a.y - b.y, a.x - b.x);
	dx = (float)(a.x - b.x) / tall;
	dy = (float)(a.y - b.y) / tall;
	while (i++ < tall)
	{
		if ((i * dx + b.x) >= 0 && (i * dx + b.x) < input->win_w &&
		(i * dy + b.y) < input->win_h && (i * dy + b.y) >= 0)
			input->im.tab[((int)(i * dx + b.x) +
			(int)(i * dy + b.y) * (input->im.size_line / 4))] = color;
	}
}

void	poly_toboxes_var(t_input *data, t_poly *poly)
{
	if (data->win_w <= poly->box.amax.x)
		poly->box.amax.x = data->win_w - 1;
	if (data->win_h <= poly->box.amax.y)
		poly->box.amax.y = data->win_h - 1;
	if (data->win_w <= poly->box.amin.x)
		poly->box.amin.x = data->win_w - 1;
	if (data->win_h <= poly->box.amin.y)
		poly->box.amin.y = data->win_h - 1;
	if (0 > poly->box.amin.x)
		poly->box.amin.x = 0;
	if (0 > poly->box.amin.y)
		poly->box.amin.y = 0;
	if (0 > poly->box.amax.x)
		poly->box.amax.x = 0;
	if (0 > poly->box.amax.y)
		poly->box.amax.y = 0;
}

int		poly_toboxes(t_input *data, t_poly *poly)
{
	int i;

	poly->box.amax.x = (int)poly->projx[0].x;
	poly->box.amax.y = (int)poly->projx[0].y;
	poly->box.amin.x = (int)poly->projx[0].x;
	poly->box.amin.y = (int)poly->projx[0].y;
	i = -1;
	while (++i < poly->nbr_pprojx)
	{
		if (poly->projx[i].x > poly->box.amax.x)
			poly->box.amax.x = poly->projx[i].x;
		if (poly->projx[i].y > poly->box.amax.y)
			poly->box.amax.y = poly->projx[i].y;
		if (poly->projx[i].x < poly->box.amin.x)
			poly->box.amin.x = poly->projx[i].x;
		if (poly->projx[i].y < poly->box.amin.y)
			poly->box.amin.y = poly->projx[i].y;
	}
	poly_toboxes_var(data, poly);
	return (1);
}

int		gettex(float ab, float bc, t_poly *poly)
{
	int ret;
	int max;

	if (!poly->check_tex)
		return (poly->mtl.ka.r * 65536 + poly->mtl.ka.g * 255 + poly->mtl.ka.b);
	max = poly->tex_tab.width * poly->tex_tab.height - 1;
	ret = (int)(((float)(ab * poly->ab.x) + (float)(bc * poly->ac.x) +
	poly->a2d.x) + (int)((float)(ab * poly->ab.y) + (float)(bc * poly->ac.y) +
	poly->a2d.y) * (poly->tex_tab.width));
	if (ret > max)
		ret = max;
	else if (ret < 0)
		ret = 0;
	return (poly->tex_tab.img[ret]);
}
