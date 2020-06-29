/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:17:42 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/29 19:04:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		init_var3(t_input *data, char *file)
{
	char *tmp;

	tmp = ft_strjoin("./texture/", file);
	if (!(data->sky.tex.tab = mlx_xpm_file_to_image(data->mlx_ad, tmp,
	&(data->sky.tex.width), &(data->sky.tex.height))))
		return (0);
	data->sky.tex.img = (unsigned int *)mlx_get_data_addr(data->sky.tex.tab,
	&(data->sky.tex.bpp), &(data->sky.tex.s_l), &(data->sky.tex.endian));
	data->sky.r = R_SKYBOX;
	data->sky.rp2 = data->sky.r * data->sky.r;
	data->sky.veci = (t_fdot){.x = 0, .y = 0, .z = 1};
	data->sky.vecj = (t_fdot){.x = 1, .y = 0, .z = 0};
	data->sky.pos = (t_fdot){.x = 0, .y = 0, .z = 0};
	data->sky.i = (t_fdot){.x = 0, .y = 0, .z = 1};
	data->sky.j = (t_fdot){.x = 1, .y = 0, .z = 0};
	free(tmp);
	return (1);
}

void	init_var2(t_data *data)
{
	int i;

	i = -1;
	while (++i < 280)
		data->keys[i] = -1;
	data->inventory = (t_inventory){.slot_one = 3, .slot_two = 0,
	.slot_three = 0, .slot_four = 0};
	data->health_bar = (t_life){.x_min = 1400, .x_max = 1556, .y_min = 813,
	.y_max = 831, .health = 20, .shield = 0};
	data->current_ammo = 10;
	data->total_ammo = 0;
	data->healanim.index_heal_anim = -1;
	data->shieldanim.index_shield_anim = -1;
	data->weaponanim.index_wpn_anim = -1;
	data->weaponanim.index_rld_anim = -1;
	data->inventory.slot_three = 0;
	data->menu_state = 1;
	data->dead_state = 0;
	data->win_state = 0;
	data->first_frame = 0;
}

void	init_var(t_input *inputs, t_data *data)
{
	inputs->win_w = WIN_SIZE_W;
	inputs->win_h = WIN_SIZE_H;
	inputs->angley = 0;
	inputs->debug = 0;
	inputs->speed = 1;
	inputs->nbrtour = 0;
	inputs->screensize = inputs->win_h * inputs->win_w;
	inputs->rotz = define_zrotmat();
	inputs->minrotz = define_minzrotmat();
	inputs->mlx_ad = mlx_init();
	inputs->win_ad = mlx_new_window(inputs->mlx_ad, inputs->win_w,
	inputs->win_h, "Doom Nukem");
	data->mlx_addrs = inputs->mlx_ad;
	data->win_addrs = inputs->win_ad;
	inputs->im.ad = mlx_new_image(inputs->mlx_ad,
	inputs->win_w, inputs->win_h);
	inputs->im.tab = (int *)mlx_get_data_addr(inputs->im.ad,
	&(inputs->im.bits_per_pixel), &(inputs->im.size_line),
	&(inputs->im.endian));
	init_var2(data);
}

void	loopandhooks(t_input *data, t_data *input)
{
	mlx_hook(data->win_ad, 6, 1L << 6, mouse_moove, data);
	mlx_hook(data->win_ad, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ad, 3, 1L << 1, key_release, data);
	mlx_hook(data->win_ad, 4, 1L << 2, mouse_press, input);
	mlx_hook(data->win_ad, 5, 1L << 3, mouse_release, input);
	mlx_hook(data->win_ad, 33, 1L << 17, clgame, input);
	mlx_loop_hook(data->mlx_ad, redraw, data);
	mlx_loop(data->mlx_ad);
}

int		main(int c, char **v)
{
	t_input	data;
	t_data	input;

	data.data_hud = &input;
	if (c != 2)
		return (write(1, "Usage: ./Doom-Nukem [map/map.txt]\n", 34));
	init_var(&data, &input);
	if (!(load_texture_data(&input)))
	{
		ft_putendl("Texture error");
		return (0);
	}
	if (!(data.map = parsing_poly(v[1], &data)))
	{
		free_addr(&data, &input);
		return (0);
	}
	gettimeofday(&input.timer.save_time, NULL);
	cp_dots(data.map, 0);
	cp_dotsobj(data.obj);
	data.rays = tab_ray(data.win_h * data.win_w, &data);
	get_plans(data.map);
	loopandhooks(&data, &input);
	return (0);
}
