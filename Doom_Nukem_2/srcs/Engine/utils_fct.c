/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:13:17 by user42            #+#    #+#             */
/*   Updated: 2020/06/29 15:21:41 by user42           ###   ########.fr       */
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
	poly->vab = getvect(poly->dot[0], poly->dot[1]);
	poly->vbc = getvect(poly->dot[1], poly->dot[2]);
	poly->vac = getvect(poly->dot[0], poly->dot[2]);
	poly->vba = getvect(poly->dot[1], poly->dot[0]);
	poly->vcb = getvect(poly->dot[2], poly->dot[1]);
	poly->vca = getvect(poly->dot[2], poly->dot[0]);
	poly->scaleab = scale(poly->vab, poly->vab);
	poly->scaleac = scale(poly->vac, poly->vac);
	poly->scaleabac = scale(poly->vab, poly->vac);
}

int		cp_dots(t_poly *poly, int isobj)
{
	int i;
	int xmax;
	int ymax;

	xmax = poly->tex_tab.width - 1;
	ymax = poly->tex_tab.height - 1;
	while (poly)
	{
		i = -1;
		if (isobj)
		{
			while (++i < 4)
				poly->cord[i].y = 1 - poly->cord[i].y;
		}
		else
			poly->check_tex = 1;
		
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
		cp_dots(obj->poly, 1);
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
