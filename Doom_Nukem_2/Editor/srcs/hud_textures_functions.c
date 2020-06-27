/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_textures_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:57 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 16:43:09 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

int		wall_square_texture(int x, int y, t_file *file)
{
	file->name_texture[5] = "image/case_doom_square_wall.xpm";
	file->position_texture[5] = (t_dot){.x = x, .y = y};
	file->image[5].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[5], &file->image[5].width, &file->image[5].height);
	file->image[5].str_image = mlx_get_data_addr(file->image[5].wall_stone,
	&file->image[5].bpp, &file->image[5].s_l, &file->image[5].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[5].wall_stone, file->position_texture[5].x,
	file->position_texture[5].y);
	return (0);
}

int		wall_blue_texture(int x, int y, t_file *file)
{
	file->name_texture[9] = "image/case_doom_blue_wall.xpm";
	file->position_texture[9] = (t_dot){.x = x, .y = y};
	file->image[9].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[9], &file->image[9].width, &file->image[9].height);
	file->image[9].str_image = mlx_get_data_addr(file->image[9].wall_stone,
	&file->image[9].bpp, &file->image[9].s_l, &file->image[9].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[9].wall_stone, file->position_texture[9].x,
	file->position_texture[9].y);
	return (0);
}

int		wall_wood_texture(int x, int y, t_file *file)
{
	file->name_texture[13] = "image/case_doom_wood_wall.xpm";
	file->position_texture[13] = (t_dot){.x = x, .y = y};
	file->image[13].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[13], &file->image[13].width, &file->image[13].height);
	file->image[13].str_image = mlx_get_data_addr(file->image[13].wall_stone,
	&file->image[13].bpp, &file->image[13].s_l, &file->image[13].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[13].wall_stone, file->position_texture[13].x,
	file->position_texture[13].y);
	return (0);
}

int		wall_green_texture(int x, int y, t_file *file)
{
	file->name_texture[15] = "image/case_doom_green_wall.xpm";
	file->position_texture[15] = (t_dot){.x = x, .y = y};
	file->image[15].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[15], &file->image[15].width, &file->image[15].height);
	file->image[15].str_image = mlx_get_data_addr(file->image[15].wall_stone,
	&file->image[15].bpp, &file->image[15].s_l, &file->image[15].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[15].wall_stone, file->position_texture[15].x,
	file->position_texture[15].y);
	return (0);
}

int		wall_quartz_texture(int x, int y, t_file *file)
{
	file->name_texture[19] = "image/case_doom_quartz_wall.xpm";
	file->position_texture[19] = (t_dot){.x = x, .y = y};
	file->image[19].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[19], &file->image[19].width, &file->image[19].height);
	file->image[19].str_image = mlx_get_data_addr(file->image[19].wall_stone,
	&file->image[19].bpp, &file->image[19].s_l, &file->image[19].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[19].wall_stone, file->position_texture[19].x,
	file->position_texture[19].y);
	return (0);
}
