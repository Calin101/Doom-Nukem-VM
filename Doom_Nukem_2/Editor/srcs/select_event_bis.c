/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_event_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:21 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:49:20 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	check_state_int_5(t_file *file, int i, int j)
{
	if (file->tab[j][i].tab_state == 22)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			doom_monster_2(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			doom_monster_2(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
	if (file->tab[j][i].tab_state == 23)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			doom_monster_3(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			doom_monster_3(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
}

void	check_state_int_6(t_file *file, int i, int j)
{
	if (file->tab[j][i].tab_state == 24)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			doom_monster_4(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			doom_monster_4(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
}

void	check_state_int_7(t_file *file, int i, int j)
{
	if (file->tab[j][i].tab_state == 15)
	{
		if (file->resetspawn == 0 || file->tab[j][i].spawn == 1)
		{
			if (file->tab[j][i].floor_state == 0)
			{
				white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
				spawn_green_start(file->tab[j][i].pos_x,
				file->tab[j][i].pos_y, file);
			}
			else
				spawn_green_start(file->tab[j][i].pos_x,
				file->tab[j][i].pos_y, file);
		}
		file->resetspawn = 1;
	}
}

void	select_visual_skybox(int x, int y, t_file *file)
{
	if ((x >= 1043 && x <= 1107) && (y >= 475 && y <= 507))
	{
		if (file->state.skybox == 0)
			print_red_visual_skybox(1043, 475, file, 1);
		else if (file->state.skybox == 1)
			print_white_visual_skybox(1043, 475, file, 1);
	}
	if ((x >= 1109 && x <= 1173) && (y >= 475 && y <= 507))
	{
		if (file->state.skybox == 0)
			print_red_visual_skybox(1109, 475, file, 2);
		else if (file->state.skybox == 2)
			print_white_visual_skybox(1109, 475, file, 2);
	}
	if ((x >= 1175 && x <= 1249) && (y >= 475 && y <= 507))
	{
		if (file->state.skybox == 0)
			print_red_visual_skybox(1175, 475, file, 3);
		else if (file->state.skybox == 3)
			print_white_visual_skybox(1175, 475, file, 3);
	}
}
