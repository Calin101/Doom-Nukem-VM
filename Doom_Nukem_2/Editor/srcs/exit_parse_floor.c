/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:19 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/28 22:40:05 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void        first_dot_floor(int x, int y, t_file *file, int fd)
{
    ft_putstr_fd("Polygon\n{\n\tdot = x:", fd);
    ft_putstr_fd(ft_itoa(x * 200), fd);
    ft_putstr_fd(", y:", fd);
    ft_putstr_fd(ft_itoa(y * 200), fd);
    ft_putstr_fd(", z:", fd);
    ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z * 100), fd);
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
}

void        first_dot_floor_bis(int x, int y, t_file *file, int fd)
{
    ft_putstr_fd("Polygon\n{\n\tdot = x:", fd);
    ft_putstr_fd(ft_itoa(x * 200), fd);
    ft_putstr_fd(", y:", fd);
    ft_putstr_fd(ft_itoa(y * 200), fd);
    ft_putstr_fd(", z:", fd);
    ft_putstr_fd(ft_itoa(file->tab[y - 1][x - 1].pos_z * 100), fd);
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
}

void        second_dot_floor(int x, int y, t_file *file, int fd)
{
    ft_putstr_fd("\n\tdot = x:", fd);
    ft_putstr_fd(ft_itoa((x + 1) * 200), fd);
    ft_putstr_fd(", y:", fd);
    ft_putstr_fd(ft_itoa(y * 200), fd);
    ft_putstr_fd(", z:", fd);
    ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z * 100), fd);
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(1), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
}

void        third_dot_floor(int x, int y, t_file *file, int fd)
{
    ft_putstr_fd("\n\tdot = x:", fd);
    ft_putstr_fd(ft_itoa(x * 200), fd);
    ft_putstr_fd(", y:", fd);
    ft_putstr_fd(ft_itoa((y + 1) * 200), fd);
    ft_putstr_fd(", z:", fd);
    ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z * 100), fd);
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(1), fd);
}

void        draw_mob(int x, int y, t_file *file, int fd)
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
        ft_putstr_fd("\n\tfile = creeper.obj\n}\n\n", fd);
    if (file->tab[y][x].tab_state == 22)
        ft_putstr_fd("\n\tfile = creeper.obj\n}\n\n", fd);
    if (file->tab[y][x].tab_state == 23)
        ft_putstr_fd("\n\tfile = creeper.obj\n}\n\n", fd);
    if (file->tab[y][x].tab_state == 24)
        ft_putstr_fd("\n\tfile = creeper.obj\n}\n\n", fd);
}