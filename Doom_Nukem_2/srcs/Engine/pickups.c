/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:12:45 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 17:18:01 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	add_item(t_input *data, int id)
{
	if (id == 0)
		data->data_hud->inventory.slot_two++;
	else if (id == 1)
		data->data_hud->inventory.slot_one++;
	else if (id == 2)
		data->data_hud->inventory.slot_three++;
	else if (id == 3)
		data->data_hud->total_ammo += 30;
}

void	hit_player(t_input *data)
{
	data->data_hud->health_bar.health -= 20 * data->data_hud->diff;
	if (data->data_hud->health_bar.health <= 0)
		dead_anim(data->data_hud);
}

void	coolobj_norm(t_object *obj, t_input *data)
{
	if (obj->type == ENEMI)
		hit_player(data);
	else if (obj->type == POTION)
	{
		add_item(data, 0);
		obj->exist = 0;
	}
	else if (obj->type == ARMOR)
	{
		add_item(data, 1);
		obj->exist = 0;
	}
	else if (obj->type == MUN)
	{
		add_item(data, 3);
		obj->exist = 0;
	}
	else if (obj->type == SCEN)
	{
		add_item(data, 2);
		obj->exist = 0;
	}
}

void	collobj(t_object *obj, t_input *data)
{
	coolobj_norm(obj, data);
	if (obj->type == CHEST)
	{
		if (data->data_hud->keys[KEY_E] == 1)
			add_item(data, 2);
		obj->exist = 0;
	}
	else if (obj->type == KEY && (data->data_hud->inventory.slot_three > 1
	&& data->data_hud->keys[KEY_E] == 1))
	{
		data->data_hud->inventory.slot_three--;
		obj->exist = 0;
	}
}

void	agro(t_object *obj, t_input *data)
{
	t_fdot dir;

	data->data_hud->diff = 1;
	dir = normalise_vec((t_fdot){-obj->pos.x, -obj->pos.y, -obj->pos.z});
	dir.x *= data->data_hud->diff;
	dir.y *= data->data_hud->diff;
	dir.z *= data->data_hud->diff;
	obj->pos.x += dir.x;
	obj->pos.y += dir.y;
	obj->pos.z += dir.z;
	obj->posrx.x += dir.x;
	obj->posrx.y += dir.y;
	obj->posrx.z += dir.z;
	mapmovep(obj->poly, dir);
}
