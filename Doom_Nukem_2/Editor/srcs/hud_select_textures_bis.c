/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_select_textures_bis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:47 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:50:48 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	select_visual_textures_2(int x, int y, t_file *file)
{
	if ((x >= 1200 && x <= 1232) && (y >= 60 && y <= 92))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1200, 60, file, 3);
		else if (file->state.mouse_state == 3)
			print_white_visual_textures(1200, 60, file, 3);
	}
	if ((x >= 1100 && x <= 1132) && (y >= 400 && y <= 432))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1100, 400, file, 5);
		else if (file->state.mouse_state == 5)
			print_white_visual_textures(1100, 400, file, 5);
	}
	if ((x >= 1050 && x <= 1082) && (y >= 400 && y <= 432))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1050, 400, file, 7);
		else if (file->state.mouse_state == 7)
			print_white_visual_textures(1050, 400, file, 7);
	}
}

void	select_visual_textures_3(int x, int y, t_file *file)
{
	if ((x >= 1150 && x <= 1182) && (y >= 400 && y <= 432))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1150, 400, file, 8);
		else if (file->state.mouse_state == 8)
			print_white_visual_textures(1150, 400, file, 8);
	}
	if ((x >= 1100 && x <= 1132) && (y >= 60 && y <= 92))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1100, 60, file, 10);
		else if (file->state.mouse_state == 10)
			print_white_visual_textures(1100, 60, file, 10);
	}
	if ((x >= 1150 && x <= 1182) && (y >= 60 && y <= 92))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1150, 60, file, 11);
		else if (file->state.mouse_state == 11)
			print_white_visual_textures(1150, 60, file, 11);
	}
}

void	select_visual_textures_4(int x, int y, t_file *file)
{
	if ((x >= 1100 && x <= 1132) && (y >= 150 && y <= 182))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1100, 150, file, 13);
		else if (file->state.mouse_state == 13)
			print_white_visual_textures(1100, 150, file, 13);
	}
	if ((x >= 1210 && x <= 1242) && (y >= 150 && y <= 182))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1210, 150, file, 14);
		else if (file->state.mouse_state == 14)
			print_white_visual_textures(1210, 150, file, 14);
	}
	if ((x >= 1080 && x <= 1112) && (y >= 260 && y <= 292))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1080, 260, file, 15);
		else if (file->state.mouse_state == 15)
			print_white_visual_textures(1080, 260, file, 15);
	}
}

void	select_visual_textures_5(int x, int y, t_file *file)
{
	if ((x >= 1130 && x <= 1162) && (y >= 260 && y <= 292))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1130, 260, file, 16);
		else if (file->state.mouse_state == 16)
			print_white_visual_textures(1130, 260, file, 16);
	}
	if ((x >= 1080 && x <= 1112) && (y >= 220 && y <= 252))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1080, 220, file, 17);
		else if (file->state.mouse_state == 17)
			print_white_visual_textures(1080, 220, file, 17);
	}
	if ((x >= 1180 && x <= 1232) && (y >= 260 && y <= 292))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1180, 260, file, 18);
		else if (file->state.mouse_state == 18)
			print_white_visual_textures(1180, 260, file, 18);
	}
	select_visual_textures_6(x, y, file);
}

void	select_visual_textures_6(int x, int y, t_file *file)
{
	if ((x >= 1050 && x <= 1082) && (y >= 325 && y <= 357))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1050, 325, file, 19);
		else if (file->state.mouse_state == 19)
			print_white_visual_textures(1050, 325, file, 19);
	}
	if ((x >= 1100 && x <= 1132) && (y >= 325 && y <= 357))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1100, 325, file, 20);
		else if (file->state.mouse_state == 20)
			print_white_visual_textures(1100, 325, file, 20);
	}
	if ((x >= 1150 && x <= 1182) && (y >= 325 && y <= 357))
	{
		if (file->state.mouse_state == 0)
			print_blue_visual_textures(1150, 325, file, 21);
		else if (file->state.mouse_state == 21)
			print_white_visual_textures(1150, 325, file, 21);
	}
}
