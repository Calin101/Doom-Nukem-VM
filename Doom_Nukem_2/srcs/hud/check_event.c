/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:26:11 by calin             #+#    #+#             */
/*   Updated: 2020/06/26 15:09:01 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	shoot_fire(t_input *input)
{
	t_fdot		coll;
	t_object	*obj;
	t_poly		*tmp;
	int			r;
	int			i;

	obj = input->obj;
	r = 720800;
	while (obj)
	{
		tmp = obj->poly;
		i = 0;
		while (tmp)
		{
			if (((getcollishot(input, tmp, &coll, r)) > -1))
			{
				if (damage_mob(obj))
					return ;
			}
			i++;
			tmp = tmp->next;
		}
		obj = obj->next;
	}
}

int		check_inputs(t_data *data)
{
	if (data->health_bar.health == 0)
	{
		dead_anim(data);
		return (0);
	}
	if ((data->keycode.r == 1 && data->current_ammo != 30) ||
	data->current_ammo == 0)
	{
		if (data->weaponanim.index_rld_anim == -1)
			data->weaponanim.index_rld_anim = 0;
		ammo(data);
	}
	return (1);
}

void	check_inputs_bis(t_data *data)
{
	if (data->keycode.one == 1 && (data->inventory.slot_one > 0 &&
	data->health_bar.shield < 100) && cooldown(data, 300000))
	{
		if (data->shieldanim.index_shield_anim == -1)
			data->shieldanim.index_shield_anim = 0;
		data->inventory.slot_one--;
		data->health_bar.shield += 10;
	}
	if (data->keycode.two == 1 && (data->inventory.slot_two > 0 &&
	data->health_bar.health < 100) && cooldown(data, 300000))
	{
		if (data->healanim.index_heal_anim == -1)
			data->healanim.index_heal_anim = 0;
		data->inventory.slot_two--;
		data->health_bar.health += 10;
	}
}

void	check_anim(t_data *data)
{
	if (data->healanim.index_heal_anim != -1)
		heal_animation(data);
	if (data->shieldanim.index_shield_anim != -1)
		shield_animation(data);
	if (data->weaponanim.index_wpn_anim != -1 && data->current_ammo > 0)
		weapon_animation(data);
	if (data->weaponanim.index_rld_anim != -1 &&
	data->weaponanim.index_wpn_anim == -1)
		reload_animation(data);
}

void	check_fire(t_data *data, t_input *input)
{
	input = (t_input *)input;
	if (data->weaponanim.index_wpn_anim == -1 && data->current_ammo > 0)
	{
		data->weaponanim.index_wpn_anim = 0;
		data->current_ammo--;
		shoot_fire(input);
	}
}
