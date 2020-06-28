/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:35:02 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 13:05:54 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	check_hooks3(t_input *inputs, int key)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT ||
	key == KEY_LEFT || key == KEY_SPACEBAR)
		moove(inputs, key);
	else if (key == KEY_J)
		inputs->debug = (inputs->debug ? 0 : 1);
	else if (key == KEY_W)
		inputs->angley += ROTY;
	else if (key == KEY_S)
		inputs->angley -= ROTY;
	else if (key == KEY_A)
		maprotateallp((t_fdot){.x = 0, .y = 0, .z = -1}, inputs);
	else if (key == KEY_D)
		maprotateallp((t_fdot){.x = 0, .y = 0, .z = 1}, inputs);
	if (key == KEY_SHIFT_LEFT)
		inputs->speed = 2.0;
}

void	check_hooks2(t_input *input, int key)
{
	if (key == KEY_1 && (input->data_hud->inventory.slot_one > 0 &&
	input->data_hud->health_bar.shield < 100) &&
	cooldown(input->data_hud, 300000))
	{
		if (input->data_hud->shieldanim.index_shield_anim == -1)
			input->data_hud->shieldanim.index_shield_anim = 0;
		input->data_hud->inventory.slot_one--;
		input->data_hud->health_bar.shield += 10;
	}
	else if (key == KEY_2 && (input->data_hud->inventory.slot_two > 0 &&
	input->data_hud->health_bar.health < 100) &&
	cooldown(input->data_hud, 300000))
	{
		if (input->data_hud->healanim.index_heal_anim == -1)
			input->data_hud->healanim.index_heal_anim = 0;
		input->data_hud->inventory.slot_two--;
		input->data_hud->health_bar.health += 10;
	}
	else
		check_hooks3(input, key);
}

void	check_hooks(t_input *input)
{
	int i;

	i = -1;
	while (++i < 80000)
	{
		if (input->data_hud->keys[i] == 1)
		{
			if (i == KEY_R && (input->data_hud->current_ammo != 30 ||
			input->data_hud->current_ammo == 0))
			{
				if (input->data_hud->weaponanim.index_rld_anim == -1)
					input->data_hud->weaponanim.index_rld_anim = 0;
				ammo(input->data_hud);
			}
			else
				check_hooks2(input, i);
		}
	}
	input->data_hud->first_frame = 1;
}
