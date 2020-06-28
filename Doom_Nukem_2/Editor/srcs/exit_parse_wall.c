/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:29 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/28 15:11:10 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void        first_dot_wall(int x, int y, t_file *file, int fd)
{
    (void)*file;
    ft_putstr_fd("Polygon\n{\n\tdot = x:", fd);
    ft_putstr_fd(ft_itoa(x * 200), fd);
    ft_putstr_fd(", y:", fd);
    ft_putstr_fd(ft_itoa(y * 200), fd);
    ft_putstr_fd(", z:", fd);
}

void        first_dot_wall_bis(int x, int y, t_file *file, int fd)
{
    (void)*file;
    (void)x;
    (void)y;
    ft_putstr_fd(ft_itoa(0), fd);
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(1), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(1), fd);
}

void        second_dot_wall(int x, int y, t_file *file, int fd)
{
    ft_putstr_fd("\n\tdot = x:", fd);
    ft_putstr_fd(ft_itoa(x * 200), fd);
    ft_putstr_fd(", y:", fd);
    ft_putstr_fd(ft_itoa(y * 200), fd);
    ft_putstr_fd(", z:", fd);
    ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z * 100), fd);
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(1), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
}

void        third_dot_wall(int x, int y, t_file *file, int fd)
{
    (void)*file;
    ft_putstr_fd("\n\tdot = x:", fd);
    ft_putstr_fd(ft_itoa((x + 1) * 200), fd);
    ft_putstr_fd(", y:", fd);
    ft_putstr_fd(ft_itoa(y * 200), fd);
    ft_putstr_fd(", z:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(1), fd);
    choose_textures_wall(file, fd, x, y);
}


void        first_dot_wall_ter(int x, int y, t_file *file, int fd)
{
    (void)*file;
    (void)x;
    (void)y;
    ft_putstr_fd(", X:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
    ft_putstr_fd(", Y:", fd);
    ft_putstr_fd(ft_itoa(0), fd);
}