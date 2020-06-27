/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_select_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:43 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:50:44 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	print_blue_visual_textures(int x, int y, t_file *file, int i)
{
	int a;

	a = 0;
	file->color.start = 178;
	file->state.mouse_state = i;
	while (a < 2)
	{
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 32) + a, .y = (y - 2) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y + 32) + a},
		(t_dot){.x = (x + 32) + a, .y = (y + 32) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x - 2) + a, .y = (y + 31) + a});
		bresenham(file, (t_dot){.x = (x + 32) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 32) + a, .y = (y + 31) + a});
		a++;
	}
}

void	print_white_visual_textures(int x, int y, t_file *file, int i)
{
	int a;

	a = 0;
	(void)i;
	file->color.start = 13816530;
	file->state.mouse_state = 0;
	while (a < 2)
	{
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 32) + a, .y = (y - 2) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y + 32) + a},
		(t_dot){.x = (x + 32) + a, .y = (y + 32) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x - 2) + a, .y = (y + 31) + a});
		bresenham(file, (t_dot){.x = (x + 32) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 32) + a, .y = (y + 31) + a});
		a++;
	}
}

void	print_red_visual_skybox(int x, int y, t_file *file, int i)
{
	int a;

	a = 0;
	file->color.start = 299710010;
	file->state.skybox = i;
	while (a < 2)
	{
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 64) + a, .y = (y - 2) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y + 32) + a},
		(t_dot){.x = (x + 64) + a, .y = (y + 32) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x - 2) + a, .y = (y + 31) + a});
		bresenham(file, (t_dot){.x = (x + 64) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 64) + a, .y = (y + 31) + a});
		a++;
	}
}

void	print_white_visual_skybox(int x, int y, t_file *file, int i)
{
	int a;

	a = 0;
	(void)i;
	file->color.start = 13816530;
	file->state.skybox = 0;
	while (a < 2)
	{
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 64) + a, .y = (y - 2) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y + 32) + a},
		(t_dot){.x = (x + 64) + a, .y = (y + 32) + a});
		bresenham(file, (t_dot){.x = (x - 2) + a, .y = (y - 2) + a},
		(t_dot){.x = (x - 2) + a, .y = (y + 31) + a});
		bresenham(file, (t_dot){.x = (x + 64) + a, .y = (y - 2) + a},
		(t_dot){.x = (x + 64) + a, .y = (y + 31) + a});
		a++;
	}
}

void	select_visual_textures(int x, int y, t_file *file)
{
	if ((x >= 1050 && x <= 1082) && (y >= 60 && y <= 92))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1050, 60, file, 1);
		else if (file->state.mouse_state == 1)
			print_white_visual_textures(1050, 60, file, 1);
	}
	if ((x >= 1200 && x <= 1232) && (y >= 400 && y <= 432))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1200, 400, file, 2);
		else if (file->state.mouse_state == 2)
			print_white_visual_textures(1200, 400, file, 2);
	}
	if ((x >= 1200 && x <= 1232) && (y >= 325 && y <= 357))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1200, 325, file, 22);
		else if (file->state.mouse_state == 22)
			print_white_visual_textures(1200, 325, file, 22);
	}
	select_visual_textures_2(x, y, file);
	select_visual_textures_3(x, y, file);
	select_visual_textures_4(x, y, file);
	select_visual_textures_5(x, y, file);
}
