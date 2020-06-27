/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:24 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:49:19 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

int		blue_case(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if ((x > 20 && x < HUD_W) && (y > 20 && y < 880))
		if ((x % 20 != 0) && (y % 20 != 0) &&
		(x >= i && x <= i + 19) && (y >= j && y <= j + 19))
		{
			while (j % 20 != 0)
			{
				i = x - (x % 20) + 1;
				while (i % 20 != 0)
				{
					file->color.red = 40;
					file->color.green = 110;
					file->color.blue = 220;
					color_pixel(file, i, j);
					i++;
				}
				j++;
			}
		}
	return (0);
}

int		green_case(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if ((x > 20 && x < HUD_W) && (y > 20 && y < 880))
		if ((x % 20 != 0) && (y % 20 != 0) &&
		(x >= i && x <= i + 19) && (y >= j && y <= j + 19))
		{
			while (j % 20 != 0)
			{
				i = x - (x % 20) + 1;
				while (i % 20 != 0)
				{
					file->color.red = 40;
					file->color.green = 250;
					file->color.blue = 120;
					color_pixel(file, i, j);
					i++;
				}
				j++;
			}
		}
	return (0);
}

int		white_case(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if ((x > 20 && x < HUD_W) && (y > 20 && y < 880))
		if ((x % 20 != 0) && (y % 20 != 0) &&
		(x >= i && x <= i + 19) && (y >= j && y <= j + 19))
		{
			while (j % 20 != 0)
			{
				i = x - (x % 20) + 1;
				while (i % 20 != 0)
				{
					file->color.red = 210;
					file->color.green = 210;
					file->color.blue = 210;
					color_pixel(file, i, j);
					i++;
				}
				j++;
			}
		}
	return (0);
}

int		wall_stone_texture(int x, int y, t_file *file)
{
	file->name_texture[1] = "image/case_doom_stone_wall.xpm";
	file->position_texture[1] = (t_dot){.x = x, .y = y};
	file->image[1].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[1], &file->image[1].width, &file->image[1].height);
	file->image[1].str_image = mlx_get_data_addr(file->image[1].wall_stone,
	&file->image[1].bpp, &file->image[1].s_l, &file->image[1].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[1].wall_stone, file->position_texture[1].x,
	file->position_texture[1].y);
	return (0);
}

int		wall_stone2_texture(int x, int y, t_file *file)
{
	file->name_texture[3] = "image/case_doom_stone2_wall.xpm";
	file->position_texture[3] = (t_dot){.x = x, .y = y};
	file->image[3].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[3], &file->image[3].width, &file->image[3].height);
	file->image[3].str_image = mlx_get_data_addr(file->image[3].wall_stone,
	&file->image[3].bpp, &file->image[3].s_l, &file->image[3].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[3].wall_stone, file->position_texture[3].x,
	file->position_texture[3].y);
	return (0);
}
