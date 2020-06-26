/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:15:21 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 15:15:25 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		cooldown(t_data *data, time_t cd)
{
	struct timeval	timer;
	long			t1;
	long			t2;

	gettimeofday(&timer, NULL);
	t1 = timer.tv_sec * 1000000 + timer.tv_usec;
	t2 = data->timer.save_time.tv_sec * 1000000 +
	data->timer.save_time.tv_usec + cd;
	if (t1 >= t2)
	{
		gettimeofday(&data->timer.save_time, NULL);
		return (1);
	}
	return (0);
}
