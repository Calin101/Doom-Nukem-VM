/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:49:00 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 17:25:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	hud_string(t_file *file)
{
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1100, 105, 0x000000,
		"Reset spawn");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1040, 170, 0x000000, "Spawn");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1110, 32, 0x000000,
		"Textures");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1170, 170, 0x000000, "End");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1110, 240, 0x000000,
		"Objects");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1120, 315, 0x000000, "Mob");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1115, 380, 0x000000,
		"Floor");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1110, 465, 0x000000,
		"Skybox");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1110, 755, 0x000000,
		"Save");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1110, 830, 0x000000,
		"Clear");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1030, 550, 0x000000,
		"Hauteur :");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1030, 590, 0x000000,
		"rot x :");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1030, 630, 0x000000,
		"rot y :");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1030, 670, 0x000000,
		"rot z :");
}

void	init_hud_bis(t_file *file)
{
	hud_string(file);
}

void	button_add_stage(t_file *file)
{
	int i;

	i = 110;
	file->color.start = 1;
	bresenham(file, (t_dot){.x = 1025, .y = 110}, (t_dot){.x = 1255, .y = 110});
	bresenham(file, (t_dot){.x = 1025, .y = 140}, (t_dot){.x = 1255, .y = 140});
	bresenham(file, (t_dot){.x = 1024, .y = 140}, (t_dot){.x = 1024, .y = 110});
	bresenham(file, (t_dot){.x = 1256, .y = 140}, (t_dot){.x = 1256, .y = 110});
	file->color.start = 16775840;
	while (++i < 140)
		bresenham(file, (t_dot){.x = 1025, .y = i}, (t_dot){.x = 1255, .y = i});
}

void	button_clear_save(t_file *file)
{
	int i;

	i = 730;
	bresenham(file, (t_dot){.x = 1025, .y = 730}, (t_dot){.x = 1255, .y = 730});
	bresenham(file, (t_dot){.x = 1025, .y = 800}, (t_dot){.x = 1255, .y = 800});
	bresenham(file, (t_dot){.x = 1024, .y = 800}, (t_dot){.x = 1024, .y = 730});
	bresenham(file, (t_dot){.x = 1256, .y = 800}, (t_dot){.x = 1256, .y = 730});
	bresenham(file, (t_dot){.x = 1025, .y = 805}, (t_dot){.x = 1255, .y = 805});
	bresenham(file, (t_dot){.x = 1025, .y = 875}, (t_dot){.x = 1255, .y = 875});
	bresenham(file, (t_dot){.x = 1024, .y = 805}, (t_dot){.x = 1024, .y = 875});
	bresenham(file, (t_dot){.x = 1256, .y = 805}, (t_dot){.x = 1256, .y = 875});
	file->color.start = 4111191;
	while (++i < 800)
		bresenham(file, (t_dot){.x = 1025, .y = i}, (t_dot){.x = 1255, .y = i});
	i = 805;
	file->color.start = 299710010;
	while (++i < 875)
		bresenham(file, (t_dot){.x = 1025, .y = i}, (t_dot){.x = 1255, .y = i});
	button_add_stage(file);
}

void	edit_z(t_file *file)
{
	char *tmp;
	char *tmp1;
	char *tmp2;
	char *tmp3;

	tmp = ft_itoa(file->tab[file->mouse.x][file->mouse.y].pos_z);
	tmp1 = ft_itoa(file->tab[file->mouse.x][file->mouse.y].rot_x);
	tmp2 = ft_itoa(file->tab[file->mouse.x][file->mouse.y].rot_y);
	tmp3 = ft_itoa(file->tab[file->mouse.x][file->mouse.y].rot_z);
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1160, 550, 0x000000, tmp);
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1160, 590, 0x000000, tmp1);
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1160, 630, 0x000000, tmp2);
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1160, 670, 0x000000, tmp3);
	free(tmp);
	free(tmp1);
	free(tmp2);
	free(tmp3);
}
