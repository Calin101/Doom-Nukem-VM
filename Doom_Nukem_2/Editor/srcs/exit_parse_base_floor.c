/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse_base_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:23 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:50:25 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		draw_base_floor(int fd)
{
	draw_base_floor_1(fd);
	draw_base_floor_2(fd);
	draw_base_floor_2(fd);
}

void		draw_base_floor_1(int fd)
{
	ft_putstr_fd("Polygon\n{\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(48), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
}

void		draw_base_floor_2(int fd)
{
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(42), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
	ft_putstr_fd("\n\ttexture = t3.xpm\n}\n\n", fd);
	ft_putstr_fd("Polygon\n{\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(48), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(42), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
}

void		draw_base_floor_3(int fd)
{
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(48), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(42), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
	ft_putstr_fd("\n\ttexture = t3.xpm\n}\n\n", fd);
}
