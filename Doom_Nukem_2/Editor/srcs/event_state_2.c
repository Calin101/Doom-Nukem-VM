/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_state_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:09 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 17:30:41 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		mouse_press_6(int x, int y, t_file *file)
{
	if ((x >= 1043 && x <= 1249) && (y >= 475 && y <= 507))
		select_visual_skybox(x, y, file);
	if ((x >= 1024 && x <= 1249) && (y >= 730 && y <= 800))
		sorting_parse(file);
	if ((x >= 1024 && x <= 1256) && (y >= 805 && y <= 875))
		clear_tab(file);
	if ((x >= 1024 && x <= 1256) && (y >= 110 && y <= 140))
		reset_spawn(file);
}

void		mouse_press_7(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if ((x > 20 && x < HUD_W) && (y > 20 && y < 880))
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
		{
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 0;
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].floor_state = 0;
		}
}
