/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:38:22 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 13:42:37 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		free_texlst(t_lstex **tex, t_input *data)
{
	t_lstex		*tmp;
	t_lstex		*next;

	tmp = *tex;
	(void)data;
	while (tmp)
	{
		next = tmp->next;
		ft_strdel(&(tmp->name));
		free(tmp);
		tmp = next;
	}
	*tex = (NULL);
}

int			push_back_tex(t_lstex *new, t_lstex **lst)
{
	t_lstex		*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void		error_free(t_lstex *new, char *buff, t_input *data)
{
	free_texlst(&new, data);
	free(buff);
}

int			init_lsttex(t_poly *poly, t_lstex **lst, t_input *data)
{
	t_lstex		*new;
	char		*buff;

	if (!(new = (t_lstex *)malloc(sizeof(t_lstex))))
		return (0);
	new->next = NULL;
	if (!(new->name = ft_strdup(poly->tex)))
		return (0);
	if (!(buff = ft_strjoin("texture/", new->name)))
		return (0);
	if (!(new->tex.tab = mlx_xpm_file_to_image(data->mlx_ad, buff,
		&new->tex.width, &new->tex.height)))
	{
		error_free(new, buff, data);
		exit(0);
	}
	if (!(new->tex.img = (unsigned int *)mlx_get_data_addr(new->tex.tab,
		&(new->tex.bpp), &(new->tex.s_l), &(new->tex.endian))))
	{
		error_free(new, buff, data);
		return (0);
	}
	push_back_tex(new, lst);
	free(buff);
	return (1);
}
