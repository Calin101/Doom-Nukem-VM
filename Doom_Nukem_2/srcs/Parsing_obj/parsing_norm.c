/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:50:43 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/26 14:43:26 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		size_mtl_file(char *file)
{
	int i;

	i = -1;
	while (file[++i])
		if (file[i] == ' ')
			return (i);
	return (0);
}

void	ft_sort_scale(char *line, t_object *obj)
{
	char *tmp;

	if (!(tmp = sort_file(line)))
		return ;
	obj->scale = ft_atof(tmp);
	free(tmp);
}

void	loop_read2(t_line *list, t_object *new, t_input *data)
{
	if (ft_strnequ_word(list->line, "type", 4))
		sort_type(list->line, new);
	else if (ft_strnequ_word(list->line, "pos", 3))
		ft_sort_pos(list->line, new, data);
	else if (ft_strnequ_word(list->line, "rot", 3))
		ft_sort_rot(list->line, new);
	else if (ft_strnequ_word(list->line, "scale", 5))
		ft_sort_scale(list->line, new);
}

void	free_new_lst(t_lst_mtl *new)
{
	ft_strdel(&(new->name));
	free(new);
	new = NULL;
}

void	free_object(t_object **obj, t_object *new)
{
	t_object		*tmp;
	t_object		*next;

	tmp = *obj;
	if (!obj)
		return ;
	while (tmp)
	{
		next = tmp->next;
		ft_strdel(&(tmp->file));
		ft_strdel(&(tmp->l_file));
		free_poly(&(tmp->poly));
		free(tmp);
		tmp = next;
	}
	*obj = NULL;
	ft_strdel(&(new->file));
	ft_strdel(&(new->l_file));
	if (new)
		free(new);
	new = NULL;
}
