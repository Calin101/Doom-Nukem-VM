/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Polcito <Polcito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:50:33 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 15:50:34 by Polcito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void		hud_base_color(t_file *file)
{
	int i;
	int j;

	i = -1;
	file->color.red = 210;
	file->color.green = 210;
	file->color.blue = 210;
	while (++i < WIDTH)
	{
		j = 0;
		while (++j < HEIGHT)
			bresenham(file, (t_dot){.x = i, .y = j}, (t_dot){.x = i, .y = j});
	}
	hud_dark_theme(file);
}

static void		hud_map_height(t_file *file)
{
	int i;

	file->color.start = 145;
	i = 20;
	while (i < HUD_W - 1)
		if (++i % 20 == 0)
			bresenham(file, (t_dot){.x = i, .y = 20},
			(t_dot){.x = i, .y = 880});
	file->color.start = 0;
	bresenham(file, (t_dot){.x = 20, .y = 20}, (t_dot){.x = 20, .y = 880});
	bresenham(file, (t_dot){.x = HUD_W, .y = 20},
	(t_dot){.x = HUD_W, .y = 880});
	bresenham(file, (t_dot){.x = 19, .y = 19}, (t_dot){.x = 19, .y = 881});
	bresenham(file, (t_dot){.x = HUD_W + 1, .y = 19},
	(t_dot){.x = HUD_W + 1, .y = 881});
}

static void		hud_map_width(t_file *file)
{
	int i;

	file->color.start = 145;
	i = 20;
	while (i < 880)
		if (++i % 20 == 0)
			bresenham(file, (t_dot){.x = 20, .y = i},
			(t_dot){.x = HUD_W, .y = i});
	file->color.start = 0;
	bresenham(file, (t_dot){.x = 19, .y = 19}, (t_dot){.x = HUD_W, .y = 19});
	bresenham(file, (t_dot){.x = 20, .y = 20}, (t_dot){.x = HUD_W, .y = 20});
	bresenham(file, (t_dot){.x = 19, .y = 881}, (t_dot){.x = HUD_W, .y = 881});
	bresenham(file, (t_dot){.x = 20 + 1, .y = 880},
	(t_dot){.x = HUD_W + 1, .y = 880});
}

static void		hud_tools(t_file *file)
{
	file->color.start = 0;
	bresenham(file, (t_dot){.x = 1020, .y = 20}, (t_dot){.x = 1260, .y = 20});
	bresenham(file, (t_dot){.x = 1020, .y = 880}, (t_dot){.x = 1260, .y = 880});
	bresenham(file, (t_dot){.x = 1260, .y = 20}, (t_dot){.x = 1260, .y = 880});
	bresenham(file, (t_dot){.x = 1020, .y = 20}, (t_dot){.x = 1020, .y = 880});
	bresenham(file, (t_dot){.x = 1019, .y = 19}, (t_dot){.x = 1261, .y = 19});
	bresenham(file, (t_dot){.x = 1019, .y = 881}, (t_dot){.x = 1261, .y = 881});
	bresenham(file, (t_dot){.x = 1019, .y = 19}, (t_dot){.x = 1019, .y = 881});
	bresenham(file, (t_dot){.x = 1261, .y = 19}, (t_dot){.x = 1261, .y = 881});
}

void			init_hud(t_file *file)
{
	hud_base_color(file);
	hud_map_width(file);
	hud_map_height(file);
	hud_tools(file);
}
