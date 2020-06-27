/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:49:40 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 20:24:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

int			deal_key(int key, t_file *file)
{
	if (key == 65307)
		exit(EXIT_SUCCESS);
	if (key == 65364)
		file->tab[file->mouse.x][file->mouse.y].pos_z -= 1;
	if (key == 65362)
		file->tab[file->mouse.x][file->mouse.y].pos_z += 1;
	if (key == 97)
		file->tab[file->mouse.x][file->mouse.y].rot_x -= 1;
	if (key == 101)
		file->tab[file->mouse.x][file->mouse.y].rot_x += 1;
	if (key == 113)
		file->tab[file->mouse.x][file->mouse.y].rot_y -= 1;
	if (key == 100)
		file->tab[file->mouse.x][file->mouse.y].rot_y += 1;
	if (key == 119)
		file->tab[file->mouse.x][file->mouse.y].rot_z -= 1;
	if (key == 99)
		file->tab[file->mouse.x][file->mouse.y].rot_z += 1;
	if (key == 122)
		file->tab[file->mouse.x][file->mouse.y].direction = 1;
	if (key == 115)
		file->tab[file->mouse.x][file->mouse.y].direction = 0;
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr, file->ptr_img, 0, 0);
	return (0);
}

int			mouse_press(int key, int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if (key == 1)
	{
		if ((x >= 1050 && x <= 1233) && (y >= 60 && y <= 440))
			select_visual_textures(x, y, file);
		if ((x > 20 && x < HUD_W) && (y > 20 && y < 880))
		{
			file->mouse.x = ((j - 1) / 20) - 1;
			file->mouse.y = ((i - 1) / 20) - 1;
			mouse_press_2(x, y, file);
			mouse_press_3(x, y, file);
			mouse_press_4(x, y, file);
			mouse_press_5(x, y, file);
			mouse_press_8(x, y, file);
		}
		if ((x >= 1024 && x <= 1256) && (y >= 110 && y <= 875))
			mouse_press_6(x, y, file);
	}
	if (key == 3)
		mouse_press_7(x, y, file);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr, file->ptr_img, 0, 0);
	return (0);
}

int			mouse_move(int x, int y, t_file *file)
{
	int i;
	int j;

	if ((x > 20 && x < HUD_W) && (y > 20 && y < 880))
	{
		i = x - (x % 20) + 1;
		j = y - (y % 20) + 1;
		if ((file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
		&& (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state == 0))
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 1;
		hud_white_case_3(file, i, j);
	}
	else
	{
		hud_white_case_2(file);
	}

	return (0);
}

void		hud_white_case_2(t_file *file)
{
	int k;
	int l;

	k = 0;
	while (k < 43)
	{
		l = 0;
		while (l < 49)
		{
			if (file->tab[k][l].tab_state == 1)
			{
				file->tab[k][l].tab_state = 0;
				white_case(file->tab[k][l].pos_x, file->tab[k][l].pos_y, file);
			}
			l++;
		}
		k++;
	}
}

void		hud_white_case_3(t_file *file, int i, int j)
{
	int k;
	int l;

	k = 0;
	while (k < 43)
	{
		l = 0;
		while (l < 49)
		{
			if (((file->tab[k][l].pos_x != i || file->tab[k][l].pos_y != j)
			&& (file->tab[k][l].tab_state == 1)))
			{
				file->tab[k][l].tab_state = 0;
				white_case(file->tab[k][l].pos_x, file->tab[k][l].pos_y, file);
			}
			l++;
		}
		k++;
	}
}
