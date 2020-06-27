/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse_wall_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:51:30 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:51:31 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		first_dot_wall_2(int x, int y, t_file *file, int fd)
{
	(void)*file;
	ft_putstr_fd("Polygon\n{\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(x), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(y), fd);
	ft_putstr_fd(", z:", fd);
}

void		first_dot_wall_bis_2(int x, int y, t_file *file, int fd)
{
	(void)*file;
	(void)x;
	(void)y;
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
}

void		second_dot_wall_2(int x, int y, t_file *file, int fd)
{
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(x), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(y), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
}

void		third_dot_wall_2(int x, int y, t_file *file, int fd)
{
	(void)*file;
	ft_putstr_fd("\n\tdot = x:", fd);
	ft_putstr_fd(ft_itoa(x), fd);
	ft_putstr_fd(", y:", fd);
	ft_putstr_fd(ft_itoa(y + 1), fd);
	ft_putstr_fd(", z:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", X:", fd);
	ft_putstr_fd(ft_itoa(0), fd);
	ft_putstr_fd(", Y:", fd);
	ft_putstr_fd(ft_itoa(1), fd);
}
