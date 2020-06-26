/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:00:04 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/26 16:54:14 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_3x3matrix	define_yrotmax(float a)
{
	t_3x3matrix ry;

	ry.a1 = cos(a);
	ry.a2 = 0;
	ry.a3 = sin(a);
	ry.b1 = 0;
	ry.b2 = 1;
	ry.b3 = 0;
	ry.c1 = -sin(a);
	ry.c2 = 0;
	ry.c3 = cos(a);
	return (ry);
}

t_3x3matrix	define_minyrotmat(void)
{
	t_3x3matrix ry;

	ry.a1 = cos(-ROTZ);
	ry.a2 = 0;
	ry.a3 = sin(-ROTZ);
	ry.b1 = 0;
	ry.b2 = 1;
	ry.b3 = 0;
	ry.c1 = -sin(-ROTZ);
	ry.c2 = 0;
	ry.c3 = cos(-ROTZ);
	return (ry);
}

t_3x3matrix	define_zrotmat(void)
{
	t_3x3matrix rz;

	rz.a1 = cos(ROTZ);
	rz.a2 = -sin(ROTZ);
	rz.a3 = 0;
	rz.b1 = sin(ROTZ);
	rz.b2 = cos(ROTZ);
	rz.b3 = 0;
	rz.c1 = 0;
	rz.c2 = 0;
	rz.c3 = 1;
	return (rz);
}

t_3x3matrix	define_minzrotmat(void)
{
	t_3x3matrix rz;

	rz.a1 = cos(-ROTZ);
	rz.a2 = -sin(-ROTZ);
	rz.a3 = 0;
	rz.b1 = sin(-ROTZ);
	rz.b2 = cos(-ROTZ);
	rz.b3 = 0;
	rz.c1 = 0;
	rz.c2 = 0;
	rz.c3 = 1;
	return (rz);
}

t_fdot		applymatpoint(t_3x3matrix matrix, t_fdot point)
{
	t_fdot newpoint;

	newpoint.x = matrix.a1 * point.x + matrix.a2 *
	point.y + matrix.a3 * point.z;
	newpoint.y = matrix.b1 * point.x + matrix.b2 *
	point.y + matrix.b3 * point.z;
	newpoint.z = matrix.c1 * point.x + matrix.c2 *
	point.y + matrix.c3 * point.z;
	return (newpoint);
}
