/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:26:48 by calin             #+#    #+#             */
/*   Updated: 2020/06/29 19:01:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		mouse_moove(int x, int y, void *param)
{
	t_input	*data;
	int		dx;
	int		dy;

	data = (t_input *)param;
	if (!data->data_hud->menu_state && !data->data_hud->dead_state
	&& !data->data_hud->win_state)
	{
		dx = WIN_SIZE_W / 2 - x;
		dy = WIN_SIZE_H / 2 - y;
		if (pow(dx, 2) >= pow(dy, 2))
		{
			if (dx > 0)
				maprotateallp((t_fdot){.x = 0, .y = 0, .z = 1}, data);
			else if (dx < 0)
				maprotateallp((t_fdot){.x = 0, .y = 0, .z = -1}, data);
		}
		else
			dy > 0 ? (data->angley += ROTY) : (data->angley -= ROTY);
		mlx_mouse_move(data->mlx_ad, data->win_ad,
		WIN_SIZE_W / 2, WIN_SIZE_H / 2);
	}
	return (0);
}

void	fct_call_redraw(t_input *input)
{
	check_hooks(input);
	check_mouse(input);
	maprotateallp((t_fdot){.x = 0, .y = 1, .z = 0}, input);
	redefineobj(input);
	redefinevector(input->map);
	getobjplans(input);
	get_plans(input->map);
	clear_im(input);
	proj_2d(input->map, input);
	moove(input, 1);
	if (input->data_hud->current_ammo == 0)
		print_reload(input->data_hud);
	check_obj(input->obj, input);
}

int		redraw(void *param)
{
	t_input *input;

	input = (t_input *)param;
	if (!input->data_hud->menu_state && !input->data_hud->dead_state
	&& !input->data_hud->win_state)
		fct_call_redraw(input);
	clear_im(input);
	if (input->data_hud->dead_state != 1 && !input->data_hud->win_state)
	{
		check_anim(input->data_hud);
		print_hud(input->data_hud);
	}
	return (0);
}
