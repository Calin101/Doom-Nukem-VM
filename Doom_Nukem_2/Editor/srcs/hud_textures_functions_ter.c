/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_textures_functions_ter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:51:05 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:51:05 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

int		key_doom(int x, int y, t_file *file)
{
	file->name_texture[33] = "image/case_key_doom.xpm";
	file->position_texture[33] = (t_dot){.x = x, .y = y};
	file->image[33].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[33], &file->image[33].width, &file->image[33].height);
	file->image[33].str_image = mlx_get_data_addr(file->image[33].wall_stone,
	&file->image[33].bpp, &file->image[33].s_l, &file->image[33].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[33].wall_stone, file->position_texture[33].x,
	file->position_texture[33].y);
	return (0);
}

int		bullet_doom(int x, int y, t_file *file)
{
	file->name_texture[35] = "image/case_bullet_doom.xpm";
	file->position_texture[35] = (t_dot){.x = x, .y = y};
	file->image[35].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[35], &file->image[35].width, &file->image[35].height);
	file->image[35].str_image = mlx_get_data_addr(file->image[35].wall_stone,
	&file->image[35].bpp, &file->image[35].s_l, &file->image[35].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[35].wall_stone, file->position_texture[35].x,
	file->position_texture[35].y);
	return (0);
}

int		doom_monster_1(int x, int y, t_file *file)
{
	file->name_texture[37] = "image/case_doom_monster_1.xpm";
	file->position_texture[37] = (t_dot){.x = x, .y = y};
	file->image[37].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[37], &file->image[37].width, &file->image[37].height);
	file->image[37].str_image = mlx_get_data_addr(file->image[37].wall_stone,
	&file->image[37].bpp, &file->image[37].s_l, &file->image[37].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[37].wall_stone, file->position_texture[37].x,
	file->position_texture[37].y);
	return (0);
}

int		doom_monster_2(int x, int y, t_file *file)
{
	file->name_texture[39] = "image/case_doom_monster_2.xpm";
	file->position_texture[39] = (t_dot){.x = x, .y = y};
	file->image[39].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[39], &file->image[39].width, &file->image[39].height);
	file->image[39].str_image = mlx_get_data_addr(file->image[39].wall_stone,
	&file->image[39].bpp, &file->image[39].s_l, &file->image[39].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[39].wall_stone, file->position_texture[39].x,
	file->position_texture[39].y);
	return (0);
}

int		doom_monster_3(int x, int y, t_file *file)
{
	file->name_texture[41] = "image/case_doom_monster_3.xpm";
	file->position_texture[41] = (t_dot){.x = x, .y = y};
	file->image[41].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
	file->name_texture[41], &file->image[41].width, &file->image[41].height);
	file->image[41].str_image = mlx_get_data_addr(file->image[41].wall_stone,
	&file->image[41].bpp, &file->image[41].s_l, &file->image[41].endian);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
	file->image[41].wall_stone, file->position_texture[41].x,
	file->position_texture[41].y);
	return (0);
}
