/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:11:51 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 15:12:04 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		print_hud(t_data *data)
{
	int i;
	int	text_to_print;

	text_to_print = NB_HUD_TEX - NB_ANIM_TEX - 2;
	if (data->menu_state == 1)
	{
		print_menu(data);
		return (0);
	}
	health(data);
	shield(data);
	print_inventory(data);
	i = -1;
	while (++i < text_to_print)
		mlx_put_image_to_window(data->mlx_addrs, data->win_addrs,
		data->tab_tex[i].img.ad, data->pos_texture[i].x,
		data->pos_texture[i].y);
	print_ammo(data);
	return (0);
}
