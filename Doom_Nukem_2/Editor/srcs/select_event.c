/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:17 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:49:22 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	check_floor(t_file *file, int floor, int i, int j)
{
	if (floor == 1)
		wall_wood_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (floor == 2)
		wall_blue_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (floor == 3)
		wall_green_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (floor == 4)
		wall_stone2_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
}

void	check_state_int(t_file *file, int i, int j)
{
	if (file->tab[j][i].tab_state == 1)
		blue_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (file->tab[j][i].tab_state == 2)
		green_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (file->tab[j][i].tab_state == 3)
		wall_stone_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (file->tab[j][i].tab_state == 5)
		wall_square_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (file->tab[j][i].tab_state == 12)
		wall_quartz_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	if (file->tab[j][i].tab_state == 13)
		wall_brick_texture(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	check_state_int_2(file, i, j);
	check_state_int_3(file, i, j);
	check_state_int_4(file, i, j);
	check_state_int_5(file, i, j);
	check_state_int_6(file, i, j);
	check_state_int_7(file, i, j);
}

void	check_state_int_2(t_file *file, int i, int j)
{
	if (file->tab[j][i].tab_state == 16)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			spawn_red_end(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			spawn_red_end(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
	if (file->tab[j][i].tab_state == 17)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			potion_heal(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			potion_heal(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
}

void	check_state_int_3(t_file *file, int i, int j)
{
	if (file->tab[j][i].tab_state == 18)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			potion_mana(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			potion_mana(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
	if (file->tab[j][i].tab_state == 19)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			key_doom(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			key_doom(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
}

void	check_state_int_4(t_file *file, int i, int j)
{
	if (file->tab[j][i].tab_state == 20)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			bullet_doom(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			bullet_doom(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
	if (file->tab[j][i].tab_state == 21)
	{
		if (file->tab[j][i].floor_state == 0)
		{
			white_case(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
			doom_monster_1(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
		}
		else
			doom_monster_1(file->tab[j][i].pos_x, file->tab[j][i].pos_y, file);
	}
}
