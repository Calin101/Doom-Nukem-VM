/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:52 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:49:05 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	init_tab(t_file *file)
{
	int x;
	int y;
	int i;
	int j;

	j = 0;
	y = 21;
	while (j < 43)
	{
		i = 0;
		x = 21;
		while (i < 49)
		{
			file->tab[j][i] = (t_tab){.pos_x = x, .pos_y = y};
			x = x + 20;
			file->tab[j][i].tab_state = 0;
			file->tab[j][i].floor_state = 0;
			i++;
		}
		y = y + 20;
		j++;
	}
}

void	clear_tab(t_file *file)
{
	int i;
	int j;

	j = 0;
	while (j < 43)
	{
		i = 0;
		while (i < 49)
		{
			if (file->tab[j][i].tab_state != 0)
				white_case((i + 1) * 20 + 1, (j + 1) * 20 + 1, file);
			file->tab[j][i].tab_state = 0;
			file->tab[j][i].floor_state = 0;
			file->tab[j][i].pos_z = 0;
			file->tab[j][i].rot_x = 0;
			file->tab[j][i].rot_y = 0;
			file->tab[j][i].rot_z = 0;
			file->tab[j][i].direction = 0;
			i++;
		}
		j++;
	}
}

void	reset_spawn(t_file *file)
{
	int i;
	int j;

	j = 0;
	file->resetspawn = 0;
	while (j < 43)
	{
		i = 0;
		while (i < 49)
		{
			if (file->tab[j][i].tab_state == 15)
			{
				white_case((i + 1) * 20 + 1, (j + 1) * 20 + 1, file);
				file->tab[j][i].tab_state = 0;
				file->tab[j][i].spawn = 0;
			}
			i++;
		}
		j++;
	}
}
