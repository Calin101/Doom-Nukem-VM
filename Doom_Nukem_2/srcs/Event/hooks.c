/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:39:51 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/26 15:46:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		checkbaryntex(t_poly *poly, t_fdot *colli)
{
	float	alpha;
	float	beta;
	t_fdot	ap;

	alpha = 0.0;
	ap = getvect(poly->dot[0], *colli);
	if (!(checkzero(poly->den1, 0.0001)))
		alpha = (poly->vBC.y * ap.z - poly->vBC.z * ap.y) / poly->den1;
	else if (!(checkzero(poly->den2, 0.0001)))
		alpha = (poly->vBC.x * ap.y - poly->vBC.y * ap.x) / poly->den2;
	else if (!(checkzero(poly->den3, 0.0001)))
		alpha = (poly->vBC.z * ap.x - poly->vBC.x * ap.z) / poly->den3;
	if (!checkzero(poly->vBC.y, 0.0001))
		beta = (poly->vAB.y * alpha - ap.y) / -poly->vBC.y;
	else if (!checkzero(poly->vBC.z, 0.0001))
		beta = (poly->vAB.z * alpha - ap.z) / -poly->vBC.z;
	else
		beta = (poly->vAB.x * alpha - ap.x) / -poly->vBC.x;
	if (alpha < 0 || beta < 0 || alpha > 1 || beta > 1 || alpha < beta)
		return (-1);
	return (1);
}

int		get_ortho(t_poly *poly, t_fdot *colli, t_ray *ray)
{
	float	t;
	float	det;
	int		ret;

	ret = -1;
	if (!(det = (poly->a * ray->x + poly->b * ray->y + poly->c * ray->z)))
		return (0);
	t = -poly->d / det;
	colli->x = t * ray->x;
	colli->y = t * ray->y;
	colli->z = t * ray->z;
	return (1);
}

int		checkseg(t_poly *poly)
{
	float pa;
	float pb;
	float pc;

	if ((pa = get3ddist((t_fdot){.x = 0, .y = 0, .z = 0},
	poly->dot[0])) < HITBOXRAY)
		return (1);
	if ((pb = get3ddist((t_fdot){.x = 0, .y = 0, .z = 0},
	poly->dot[1])) < HITBOXRAY)
		return (1);
	if ((pc = get3ddist((t_fdot){.x = 0, .y = 0, .z = 0},
	poly->dot[2])) < HITBOXRAY)
		return (1);
	return (0);
}

int		check_gravity(t_poly *poly)
{
	t_fdot ortho;

	while (poly)
	{
		if ((get_ortho(poly, &ortho, &(t_ray){.x = poly->a,
		.y = poly->b, .z = poly->b})))
		{
			if (get3ddist((t_fdot){.x = 0, .y = 0, .z = 0},
			ortho) < HITBOXGRAVITY)
			{
				if (checkbaryntex(poly, &ortho))
					return (1);
				else if (checkseg(poly))
					return (1);
			}
		}
		poly = poly->next;
	}
	return (0);
}

int		check_colli(t_poly *poly)
{
	t_fdot ortho;

	while (poly)
	{
		if ((get_ortho(poly, &ortho, &(t_ray){.x = poly->a,
		.y = poly->b, .z = poly->b})))
		{
			if (get3ddist((t_fdot){.x = 0, .y = 0, .z = 0}, ortho) < HITBOXRAY)
			{
				if (checkbaryntex(poly, &ortho))
					return (1);
				else if (checkseg(poly))
					return (1);
			}
		}
		poly = poly->next;
	}
	return (0);
}
