/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:43:08 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 22:38:47 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		sort_tfdot_pos(char *line, t_fdot *dot)
{
	int		i;
	char	**tab;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	if (!(tab = ft_strsplit(line + i, ' ')))
		return (0);
	if (ft_avlen(tab) != 3)
		return (0);
	dot->x = ft_atof(tab[0]);
	dot->y = ft_atof(tab[1]);
	dot->z = ft_atof(tab[2]);
	free_tab(&tab);
	return (1);
}

int		parse_fobj2(t_line *list, t_file_obj *file, t_input *d, t_poly **poly)
{
	static char	*tmp;

	if (ft_strnequ_word(list->line, "mtllib ", 7))
		if (!(sort_mtl(d, list->line, file)))
			return (0);
	if (ft_strnequ_word(list->line, "v ", 2))
		if (!(sort_tfdot_pos(list->line, &(file->v[file->index.i++]))))
			return (0);
	if (ft_strnequ_word(list->line, "vt ", 3))
		if (!(sort_t2d(list->line, &(file->vt[file->index.j++]))))
			return (0);
	if (ft_strnequ_word(list->line, "usemtl ", 7))
		tmp = list->line + 7;
	if (ft_strnequ_word(list->line, "vn ", 3))
		if (!(sort_tfdot(list->line, &(file->vn[file->index.k++]))))
			return (0);
	if (ft_strnequ_word(list->line, "f ", 2))
		if (!(sort_poly(list->line + 2, poly, *file, tmp)))
			return (0);
	return (1);
}
