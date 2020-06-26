/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:28:17 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 18:30:04 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		checkbary(t_poly *poly, t_fdot *colli)
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
	return (gettex(alpha, beta, poly));
}

int		getcolli(t_input *data, t_poly *poly, t_fdot *colli, int r)
{
	float	t;
	float	det;
	int		ret;
	float	dist;

	ret = -1;
	if (!(det = (poly->a * data->rays[r].x + poly->b * data->rays[r].y +
	poly->c * data->rays[r].z)))
		return (-1);
	t = -poly->d / det;
	colli->x = t * data->rays[r].x;
	colli->y = t * data->rays[r].y;
	colli->z = t * data->rays[r].z;
	if (data->rays[r].distcolli == -1)
	{
		if ((ret = checkbary(poly, colli)) != -1)
			data->rays[r].distcolli = getpow3ddist(*colli);
	}
	else if ((dist = getpow3ddist(*colli)) < data->rays[r].distcolli)
		if ((ret = checkbary(poly, colli)) != -1)
			data->rays[r].distcolli = dist;
	return (ret);
}

int		getcollishot(t_input *data, t_poly *poly, t_fdot *colli, int r)
{
	float	t;
	float	det;
	int		ret;

	ret = -1;
	if (!(det = (poly->a * data->rays[r].x + poly->b *
	data->rays[r].y + poly->c * data->rays[r].z)))
		return (-1);
	t = -poly->d / det;
	colli->x = t * data->rays[r].x;
	colli->y = t * data->rays[r].y;
	colli->z = t * data->rays[r].z;
	ret = checkbaryntex(poly, colli);
	return (ret);
}

int		process_ray(t_proray ray, t_input *data, t_poly *poly)
{
	t_fdot	colli;

	return (getcolli(data, poly, &colli, ray.y * data->win_w + ray.x));
}

void	*ray_boxes(void *para)
{
	t_dot		p;
	int			ret;
	t_thread	*thread;

	thread = (t_thread *)para;
	p = thread->box.amin;
	if (!(thread->box.amin.x == thread->box.amax.x ||
	thread->box.amin.y == thread->box.amax.y))
	{
		while (p.y <= thread->box.amax.y)
		{
			ret = process_ray((t_proray){.x = p.x, .y = p.y, 0},
			thread->inputs, thread->poly);
			if (ret != -1)
				thread->inputs->im.tab[p.x + p.y *
				thread->inputs->win_w] = ret;
			p.x++;
			if (p.x == thread->box.amax.x)
			{
				p.y++;
				p.x = thread->box.amin.x;
			}
		}
	}
	return (NULL);
}