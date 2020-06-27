/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:12 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 17:16:07 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		mouse_press_2(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
	&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j
	&& file->state.mouse_state == 0)
		file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 2;
	if (file->state.mouse_state == 1)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 3;
	if (file->state.mouse_state == 2)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].floor_state = 4;
	if (file->state.mouse_state == 3)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 5;
	if (file->state.mouse_state == 5)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].floor_state = 2;
}

void		mouse_press_3(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if (file->state.mouse_state == 10)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 12;
	if (file->state.mouse_state == 11)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 13;
	if (file->state.mouse_state == 13)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
		{
			if (file->resetspawn == 0)
			{
				file->tab[((j - 1) / 20) - 1][((i -
				1) / 20) - 1].tab_state = 15;
				file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].spawn = 1;
			}
		}
}

void		mouse_press_4(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if (file->state.mouse_state == 14)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 16;
	if (file->state.mouse_state == 15)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 17;
	if (file->state.mouse_state == 16)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 18;
	if (file->state.mouse_state == 17)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 19;
	if (file->state.mouse_state == 18)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 20;
}

void		mouse_press_5(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if (file->state.mouse_state == 19)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 21;
	if (file->state.mouse_state == 20)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 22;
	if (file->state.mouse_state == 21)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 23;
	if (file->state.mouse_state == 22)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].tab_state = 24;
}

void		mouse_press_8(int x, int y, t_file *file)
{
	int i;
	int j;

	i = x - (x % 20) + 1;
	j = y - (y % 20) + 1;
	if (file->state.mouse_state == 7)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i &&
		file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].floor_state = 1;
	if (file->state.mouse_state == 8)
		if (file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_x == i
		&& file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].pos_y == j)
			file->tab[((j - 1) / 20) - 1][((i - 1) / 20) - 1].floor_state = 3;
}
