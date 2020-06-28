/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:29:39 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 12:30:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	win_anim(t_data *data)
{
	data->win_state = 1;
	mlx_mouse_show(data->mlx_addrs, data->win_addrs);
	mlx_clear_window(data->mlx_addrs, data->win_addrs);
	data->name_texture[0] = "srcs/hud/images/win.xpm";
	data->tab_tex[0].img.ad = mlx_xpm_file_to_image(data->mlx_addrs,
	data->name_texture[0], &data->tab_tex[0].width, &data->tab_tex[0].height);
	data->tab_tex[0].img.tab =
	(int *)mlx_get_data_addr(data->tab_tex[0].img.ad,
	&(data->tab_tex[0].img.bits_per_pixel), &(data->tab_tex[0].img.size_line),
	&(data->tab_tex[0].img.endian));
	mlx_put_image_to_window(data->mlx_addrs, data->win_addrs,
	data->tab_tex[0].img.ad, 0, 0);
	mlx_put_image_to_window(data->mlx_addrs, data->win_addrs,
	data->menu_texture[3].img.ad, data->menu_texture[3].pos_text.x,
	data->menu_texture[3].pos_text.y);
}