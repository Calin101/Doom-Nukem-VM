/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:48:55 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 18:26:01 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

int		out(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		loop(t_file *file)
{
	int i;
	int j;

	init_hud_bis(file);
	texture_images_init(file);
	edit_z(file);
	i = 0;
	j = 0;
	while (j < 43)
	{
		i = 0;
		while (i < 49)
		{
			check_floor(file, file->tab[j][i].floor_state, i, j);
			check_state_int(file, i, j);
			i++;
		}
		j++;
	}
	mlx_do_sync(file->mlx_ptr);
	return (0);
}

int		main(int ac, char **av)
{
	t_file	*file;

	(void)**av;
	file = malloc(sizeof(t_file));
	if (ac > 1)
		return (write(1, "wrong usage\n", 12));
	if (!(display_window(file)))
		return (0);
	init_tab(file);
	mlx_hook(file->win_ptr, 2, 1L << 0, deal_key, file);
	mlx_hook(file->win_ptr, 4, 1L << 2, mouse_press, file);
	mlx_hook(file->win_ptr, 6, 1L << 6, mouse_move, file);
	mlx_hook(file->win_ptr, 33, 1L << 17, out, file);
	mlx_loop_hook(file->mlx_ptr, loop, file);
	mlx_loop(file->mlx_ptr);
	return (0);
}
