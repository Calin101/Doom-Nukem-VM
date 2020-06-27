/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:37 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 18:27:25 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

int			init_tab_texture(t_file *file)
{
	if(!(file->name_texture[0] = "image/doom_stone_wall.xpm") ||
	!(file->name_texture[4] = "image/doom_wood_wall.xpm") ||
	!(file->name_texture[6] = "image/doom_quartz_wall.xpm") ||
	!(file->name_texture[8] = "image/doom_stone2_wall.xpm") ||
	!(file->name_texture[10] = "image/doom_blue_wall.xpm") ||
	!(file->name_texture[12] = "image/doom_green_wall.xpm") ||
	!(file->name_texture[14] = "image/doom_brick_wall.xpm") ||
	!(file->name_texture[16] = "image/doom_square_wall.xpm") ||
	!(file->name_texture[24] = "image/doom_green_spawn.xpm") ||
	!(file->name_texture[26] = "image/doom_red_spawn.xpm") ||
	!(file->name_texture[28] = "image/heal_potion.xpm") ||
	!(file->name_texture[30] = "image/mana_potion.xpm") ||
	!(file->name_texture[34] = "image/bullet_doom.xpm") ||
	!(file->name_texture[36] = "image/doom_monster_1.xpm") ||
	!(file->name_texture[38] = "image/doom_monster_2.xpm") ||
	!(file->name_texture[40] = "image/doom_monster_3.xpm") ||
	!(file->name_texture[42] = "image/doom_monster_4.xpm") ||
	!(file->name_texture[44] = "image/skybox_day.xpm") ||
	!(file->name_texture[46] = "image/skybox_night.xpm") ||
	!(file->name_texture[48] = "image/skybox_dust.xpm"))
		return (0);
	init_tab_texture_2(file);
	init_tab_texture_3(file);
	return (1);
}

void		init_tab_texture_2(t_file *file)
{
	file->position_texture[0] = (t_dot){.x = 1050, .y = 60};
	file->position_texture[4] = (t_dot){.x = 1050, .y = 400};
	file->position_texture[6] = (t_dot){.x = 1100, .y = 60};
	file->position_texture[8] = (t_dot){.x = 1200, .y = 400};
	file->position_texture[10] = (t_dot){.x = 1100, .y = 400};
	file->position_texture[12] = (t_dot){.x = 1150, .y = 400};
	file->position_texture[14] = (t_dot){.x = 1150, .y = 60};
	file->position_texture[16] = (t_dot){.x = 1200, .y = 60};
	file->position_texture[24] = (t_dot){.x = 1100, .y = 150};
	file->position_texture[26] = (t_dot){.x = 1210, .y = 150};
	file->position_texture[28] = (t_dot){.x = 1080, .y = 260};
	file->position_texture[30] = (t_dot){.x = 1130, .y = 260};
	file->position_texture[34] = (t_dot){.x = 1180, .y = 260};
	file->position_texture[36] = (t_dot){.x = 1050, .y = 325};
	file->position_texture[38] = (t_dot){.x = 1100, .y = 325};
	file->position_texture[40] = (t_dot){.x = 1150, .y = 325};
	file->position_texture[42] = (t_dot){.x = 1200, .y = 325};
	file->position_texture[44] = (t_dot){.x = 1043, .y = 475};
	file->position_texture[46] = (t_dot){.x = 1109, .y = 475};
	file->position_texture[48] = (t_dot){.x = 1175, .y = 475};
}

void		init_tab_texture_3(t_file *file)
{
	int i;

	i = 0;
	while (i % 2 == 0 && i <= 48)
	{
		if (!(file->image[i].wall_stone = mlx_xpm_file_to_image(file->mlx_ptr,
		file->name_texture[i], &file->image[i].width, &file->image[i].height)))
		{
			ft_putendl("Texture error");
		}
		file->image[i].str_image = mlx_get_data_addr(file->image[i].wall_stone,
		&file->image[i].bpp, &file->image[i].s_l, &file->image[i].endian);
		if (i == 0)
			i = i + 4;
		else if (i == 30)
			i += 4;
		else if (i == 16)
			i = i + 8;
		else
			i += 2;
	}
}

int			texture_images_init(t_file *file)
{
	int i;

	i = 0;
	while (i % 2 == 0 && i <= 48)
	{
		mlx_put_image_to_window(file->mlx_ptr, file->win_ptr,
		file->image[i].wall_stone, file->position_texture[i].x,
		file->position_texture[i].y);
		if (i == 0)
			i = i + 4;
		else if (i == 30)
			i += 4;
		else if (i == 16)
			i = i + 8;
		else
			i += 2;
	}
	return (0);
}
