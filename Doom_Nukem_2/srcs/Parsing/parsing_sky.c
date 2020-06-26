/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sky.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:14:38 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/26 13:43:02 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	sort_skybox(t_input *data, char *file)
{
	char	*tmp;

	if (!(tmp = sort_file(file)))
		exit(0);
	if (!(init_var3(data, tmp)))
		exit(0);
	free(tmp);
	return (1);
}
