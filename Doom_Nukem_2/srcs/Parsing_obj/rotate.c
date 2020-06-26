/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:25:41 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/26 14:48:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_fdot	rotx(t_fdot in, float degree)
{
	float	vsin;
	float	vcos;
	t_fdot	new;

	vsin = sin(degree * (M_PI / 180));
	vcos = cos(degree * (M_PI / 180));
	new.x = in.x;
	new.y = in.y * vcos + in.z * -vsin;
	new.z = in.y * vsin + in.z * vcos;
	return (new);
}

t_fdot	roty(t_fdot in, float degree)
{
	float	vsin;
	float	vcos;
	t_fdot	new;

	vsin = sin(degree * (M_PI / 180));
	vcos = cos(degree * (M_PI / 180));
	new.x = in.x * vcos + in.z * vsin;
	new.y = in.y;
	new.z = in.x * -vsin + in.z * vcos;
	return (new);
}

t_fdot	rotz(t_fdot in, float degree)
{
	float	vsin;
	float	vcos;
	t_fdot	new;

	vsin = sin(degree * (M_PI / 180));
	vcos = cos(degree * (M_PI / 180));
	new.x = in.x * vcos + in.y * -vsin;
	new.y = in.x * vsin + in.y * vcos;
	new.z = in.z;
	return (new);
}
