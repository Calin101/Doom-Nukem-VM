/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:13:17 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 16:14:03 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_ray	*tab_ray(int nbrpix, t_input *data)
{
	t_ray	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_ray) * nbrpix);
	while (i < data->screensize)
	{
		new[i].x = 1;
		new[i].y = (-X_VIEW / 2 + i % data->win_w /
		(float)data->win_w * X_VIEW);
		new[i].z = (Z_VIEW / 2 - i / data->win_w /
		(float)data->win_h * Z_VIEW);
		new[i].distcolli = -1;
		new[i].dp1 = 0;
		new[i].dp2 = 0;
		i++;
	}
	return (new);
}

void	initialize_vec_poly(t_poly *poly)
{
	poly->vAB = getvect(poly->dot[0], poly->dot[1]);
	poly->vBC = getvect(poly->dot[1], poly->dot[2]);
	poly->vAC = getvect(poly->dot[0], poly->dot[2]);
	poly->vBA = getvect(poly->dot[1], poly->dot[0]);
	poly->vCB = getvect(poly->dot[2], poly->dot[1]);
	poly->vCA = getvect(poly->dot[2], poly->dot[0]);
	poly->scaleAB = scale(poly->vAB, poly->vAB);
	poly->scaleAC = scale(poly->vAC, poly->vAC);
	poly->scaleABAC = scale(poly->vAB, poly->vAC);
}

int		cp_dots(t_poly *poly)
{
	int i;
	int xmax;
	int ymax;

	xmax = poly->tex_tab.width - 1;
	ymax = poly->tex_tab.height - 1;
	while (poly)
	{
		i = -1;
		poly->ab = get2dvect((t_2d){.x = poly->cord[0].x * xmax, .y =
		poly->cord[0].y * ymax}, (t_2d){.x = poly->cord[1].x * xmax,
		.y = poly->cord[1].y * ymax});
		poly->ac = get2dvect((t_2d){.x = poly->cord[1].x * xmax, .y =
		poly->cord[1].y * ymax}, (t_2d){.x = poly->cord[2].x * xmax,
		.y = poly->cord[2].y * ymax});
		poly->a2d.x = poly->cord[0].x * xmax;
		poly->a2d.y = poly->cord[0].y * ymax;
		initialize_vec_poly(poly);
		while (++i < 4)
			poly->rotx[i] = poly->dot[i];
		poly = poly->next;
	}
	return (1);
}

void	cp_dotsobj(t_object *obj)
{
	while (obj)
	{
		cp_dots(obj->poly);
		obj->posrx = obj->pos;
		obj->exist = 1;
		obj->hp = 100;
		get_plans(obj->poly);
		obj = obj->next;
	}
}

void	free_addr(t_input *input, t_data *data)
{
	int i;

	i = -1;
	while (++i < NB_HUD_TEX - NB_ANIM_TEX)
		mlx_destroy_image(data->mlx_addrs, data->tab_tex[i].img.ad);
	i = -1;
	while (++i < NB_ANIM_TEX)
	{
		mlx_destroy_image(data->mlx_addrs,
		data->healanim.anim_texture[i].img.ad);
		mlx_destroy_image(data->mlx_addrs,
		data->shieldanim.anim_texture[i].img.ad);
	}
	i = -1;
	while (++i < 4)
		mlx_destroy_image(data->mlx_addrs, data->menu_texture[i].img.ad);
	mlx_destroy_image(input->mlx_ad, input->im.ad);
	mlx_destroy_window(input->mlx_ad, input->win_ad);
	free(data->mlx_addrs);
	exit(0);
}
