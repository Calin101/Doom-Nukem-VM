/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:39:49 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 13:41:58 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_lstex		*tex_cmp(char *tex, t_lstex *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!(ft_strcmp(lst->name, tex)))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int			load_tex(t_poly **poly, t_input *data)
{
	t_lstex		*lst;
	t_poly		*tmp;

	tmp = *poly;
	lst = NULL;
	while (tmp)
	{
		if (!(tex_cmp(tmp->tex, lst)))
		{
			if (!(init_lsttex(tmp, &lst, data)))
			{
				free_texlst(&lst, data);
				return (0);
			}
		}
		tmp->tex_tab = tex_cmp(tmp->tex, lst)->tex;
		tmp = tmp->next;
	}
	free_texlst(&lst, data);
	return (1);
}
