/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:33:24 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 15:38:22 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		mouse_release(int button, int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (y > 0)
	{
		if (button == 1)
			data->keycode.l_click = 0;
	}
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (x > 625 && x < 915 && y > 425 && y < 525)
	{
		data->menu_state = 0;
		mlx_mouse_hide(data->mlx_addrs, data->win_addrs);
	}
	if (data->menu_state == 1 && (x > 625 && x < 915 && y > 576 && y < 671))
		printf("Exec editor\n");
	if ((data->menu_state == 1 || data->dead_state == 1)
	&& (x > 625 && x < 915 && y > 727 && y < 822))
		close_game(data);
	if (y > 0)
	{
		if (button == 1)
			data->keycode.l_click = 1;
	}
	return (0);
}

int		key_release(int keycode, void *param)
{
	t_input *data;

	data = (t_input *)param;
	data->data_hud->keys[keycode] = 0;
	return (0);
}

int		key_press(int keycode, void *param)
{
	t_input *data;

	data = (t_input *)param;
	printf("keypress %d\n", keycode);
	data->data_hud->keys[keycode] = 1;
	if (keycode == KEY_ESCAPE)
		close_game(data->data_hud);
	if (keycode == KEY_P)
	{
		mlx_mouse_show(data->mlx_ad, data->win_ad);
		data->data_hud->menu_state = 1;
	}
	if (keycode == KEY_T)
		dead_anim(data->data_hud);
	if (keycode == KEY_R)
		data->data_hud->keys[keycode] = 1;
	if (keycode == KEY_E)
		data->data_hud->keys[keycode] = 1;
	return (0);
}

void	check_mouse(t_input *input)
{
	if (input->data_hud->menu_state == 0
	&& input->data_hud->keycode.l_click == 1 &&
	cooldown(input->data_hud, 150000) &&
	input->data_hud->first_frame == 1 && input->data_hud->current_ammo >= 0)
		check_fire(input->data_hud, input);
}
