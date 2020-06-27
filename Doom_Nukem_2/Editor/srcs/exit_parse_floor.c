/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:19 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:50:20 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		first_dot_floor(int x, int y, t_file *file, int fd)
{
	ft_putstr_fd("Polygon\n{\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(x), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(y), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
}

void		second_dot_floor(int x, int y, t_file *file, int fd)
{
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(x + 1), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(y), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
}

void		third_dot_floor(int x, int y, t_file *file, int fd)
{
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(x), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(y + 1), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
}

void		draw_mob(int x, int y, t_file *file, int fd)
{
	ft_putstr_fd("Object\n{\n\ttype = ennemy\n\tpos = x:", fd);
	ft_putstr_fd(ft_itoa(x), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(y), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z), fd);
	ft_putstr_fd("\n\trot = x:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].rot_x), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].rot_y), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].rot_z), fd);
	if (file->tab[y][x].tab_state == 21)
		ft_putstr_fd("\n\tfile = mob_1.obj\n}\n\n", fd);
	if (file->tab[y][x].tab_state == 22)
		ft_putstr_fd("\n\tfile = mob_2.obj\n}\n\n", fd);
	if (file->tab[y][x].tab_state == 23)
		ft_putstr_fd("\n\tfile = mob_3.obj\n}\n\n", fd);
	if (file->tab[y][x].tab_state == 24)
		ft_putstr_fd("\n\tfile = mob_4.obj\n}\n\n", fd);
}
