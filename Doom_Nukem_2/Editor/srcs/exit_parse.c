/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:30 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:49:16 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		sorting_parse(t_file *file)
{
	int		i;
	int		j;
	int		fd;
	char	*name;

	j = -1;
	name = ft_strjoin("./map/", ft_itoa(rand()));
	fd = open(ft_strcat(name, ".txt"), O_CREAT | O_WRONLY, 0644);
	parse_skybox(file, fd);
	draw_base_floor(fd);
	while (++j < 43)
	{
		i = -1;
		while (++i < 49)
		{
			if (file->tab[j][i].floor_state > 0 &&
			file->tab[j][i].floor_state < 5)
				draw_floor(i, j, file, fd);
			if (file->tab[j][i].tab_state > 2 && file->tab[j][i].tab_state < 15)
				draw_wall(i, j, file, fd);
			if (file->tab[j][i].tab_state > 14
			&& file->tab[j][i].tab_state < 25)
				draw_mob_and_object(i, j, file, fd);
		}
	}
}

void		draw_floor(int x, int y, t_file *file, int fd)
{
	int a;

	a = 0;
	while (a < 2)
	{
		if (a == 1)
		{
			x++;
			y++;
		}
		first_dot_floor(x, y, file, fd);
		if (a == 1)
		{
			x--;
			y--;
		}
		second_dot_floor(x, y, file, fd);
		third_dot_floor(x, y, file, fd);
		choose_textures_floor(file, fd, x, y);
		a++;
	}
}

void		draw_wall(int x, int y, t_file *file, int fd)
{
	int a;

	a = 0;
	if (file->tab[y][x].direction == 1)
		draw_wall_2(x, y, file, fd);
	else
		while (a < 2)
		{
			if (a == 1)
				x++;
			first_dot_wall(x, y, file, fd);
			if (a == 1)
				ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z), fd);
			else
				ft_putstr_fd(ft_itoa(0), fd);
			first_dot_wall_bis(x, y, file, fd);
			if (a == 1)
				x--;
			second_dot_wall(x, y, file, fd);
			third_dot_wall(x, y, file, fd);
			choose_textures_wall(file, fd, x, y);
			a++;
		}
}

void		draw_wall_2(int x, int y, t_file *file, int fd)
{
	int a;

	a = 0;
	while (a < 2)
	{
		if (a == 1)
			y++;
		first_dot_wall_2(x, y, file, fd);
		if (a == 1)
			ft_putstr_fd(ft_itoa(file->tab[y][x].pos_z), fd);
		else
			ft_putstr_fd(ft_itoa(0), fd);
		first_dot_wall_bis_2(x, y, file, fd);
		if (a == 1)
			y--;
		second_dot_wall_2(x, y, file, fd);
		third_dot_wall_2(x, y, file, fd);
		choose_textures_wall(file, fd, x, y);
		a++;
	}
}

void		draw_mob_and_object(int x, int y, t_file *file, int fd)
{
	if (file->tab[y][x].tab_state > 20 && file->tab[y][x].tab_state < 25)
		draw_mob(x, y, file, fd);
	else
	{
		if (file->tab[y][x].tab_state == 16)
			ft_putstr_fd("Object\n{\n\ttype = end\n\tpos = x:", fd);
		else
			ft_putstr_fd("Object\n{\n\ttype = object\n\tpos = x:", fd);
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
		choose_objects_file(file, fd, x, y);
	}
}
