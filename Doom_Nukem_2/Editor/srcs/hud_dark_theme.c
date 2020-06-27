/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_dark_theme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:36 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:49:11 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	hud_dark_theme_bis(t_file *file)
{
	int i;
	int j;

	i = -1;
	while (++i < 19)
	{
		j = 19;
		while (++j <= 880)
			bresenham(file, (t_dot){.x = i, .y = j}, (t_dot){.x = i, .y = j});
	}
	i = 1000;
	while (++i < 1020)
	{
		j = 19;
		while (++j <= 880)
			bresenham(file, (t_dot){.x = i, .y = j}, (t_dot){.x = i, .y = j});
	}
	i = 1260;
	while (++i < 1280)
	{
		j = 19;
		while (++j <= 880)
			bresenham(file, (t_dot){.x = i, .y = j}, (t_dot){.x = i, .y = j});
	}
}

void	hud_dark_theme(t_file *file)
{
	int i;
	int j;

	i = -1;
	file->color.red = 60;
	file->color.green = 60;
	file->color.blue = 60;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < 20)
			bresenham(file, (t_dot){.x = i, .y = j}, (t_dot){.x = i, .y = j});
	}
	i = -1;
	while (++i < WIDTH)
	{
		j = 880;
		while (++j < HEIGHT)
			bresenham(file, (t_dot){.x = i, .y = j}, (t_dot){.x = i, .y = j});
	}
	hud_dark_theme_bis(file);
}

int		doom_monster_4(int x, int y, t_file *file)
{
	file->name_texture[43] = "image/case_doom_monster_4.xpm";
	file->position_texture[43] = (t_dot){.x = x, .y = y};
	file->image[43].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[43], &file->image[43].width, &file->image[43].height);
	file->image[43].str_image = mlx_get_data_addr(file->image[43].wall_stone,
	&file->image[43].bpp, &file->image[43].s_l, &file->image[43].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[43].wall_stone, file->position_texture[43].x,
	file->position_texture[43].y);
	return (0);
}
