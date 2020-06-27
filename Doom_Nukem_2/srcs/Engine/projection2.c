/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:08:24 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 14:15:23 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		projxy(t_poly *map, t_input *data)
{
	float	fov_x;
	float	fov_z;
	float	tmp;
	int		j;

	fov_x = X_VIEW;
	fov_z = Z_VIEW;
	j = -1;
	while (++j < map->nbr_pprojx)
	{
		tmp = map->projx[j].x;
		map->projx[j].x = ((map->projx[j].y / map->projx[j].x) + fov_x / 2) *
		((float)(data->win_w - 1) / fov_x);
		map->projx[j].y = (-(map->projx[j].z / tmp) + fov_z / 2) *
		((float)(data->win_h - 1) / fov_z);
	}
	if (map->nbr_pprojx)
		return (1);
	return (0);
}

int		proj_2d(t_poly *map, t_input *data)
{
	int				i;
	int				ret;

	i = -1;
	while (map)
	{
		i++;
		separate_points(map);
		ret = projxy(map, data);
		if (ret)
		{
			map->isvisible = 1;
			poly_toboxes(data, map);
		}
		else
			map->isvisible = 0;
		map = map->next;
	}
	thread_start(data, data->map);
	get_objpo(data->obj, data);
	get_sky(data);
	mlx_put_image_to_window(data->mlx_ad, data->win_ad, data->im.ad, 0, 0);
	return (1);
}

int		in_poly(t_poly *poly, t_fdot col)
{
	t_fdot ap;
	t_fdot bp;
	t_fdot cp;

	cp = (t_fdot){.x = 0, .y = 0, .z = 0};
	ap = getvect(poly->dot[0], col);
	bp = getvect(poly->dot[1], col);
	bp = getvect(poly->dot[2], col);
	if ((scale(vectoriel_product(poly->vab, ap),
	vectoriel_product(ap, poly->vac)) >= 0)
	&& (scale(vectoriel_product(poly->vba, bp),
	vectoriel_product(bp, poly->vbc)) >= 0)
	&& (scale(vectoriel_product(poly->vca, cp),
	vectoriel_product(cp, poly->vcb))) >= 0)
		return (0xFF);
	return (0);
}

int		alkashisolver(t_poly *poly, t_fdot col)
{
	float		sum;
	float		a;
	t_alkashi	al;

	sum = 0;
	al.ab = get3ddist(poly->dot[0], poly->dot[1]);
	al.bc = get3ddist(poly->dot[1], poly->dot[2]);
	al.ca = get3ddist(poly->dot[2], poly->dot[0]);
	al.ap = get3ddist(col, poly->dot[0]);
	al.bp = get3ddist(col, poly->dot[1]);
	al.cp = get3ddist(col, poly->dot[2]);
	a = ((-al.ab * al.ab + al.bp * al.bp + al.ap * al.ap) /
	(-2 * al.bp * al.ap));
	sum += acos(a);
	sum += acos((-al.bc * al.bc + al.cp * al.cp +
	al.bp * al.bp) / (-2 * al.bp * al.cp));
	sum += acos((-al.ca * al.ca + al.cp * al.cp +
	al.ap * al.ap) / (-2 * al.cp * al.ap));
	if (sum >= 6.27 && sum <= 6.29)
		return (0xFF);
	return (0);
}
