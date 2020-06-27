/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:14:48 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 13:49:07 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 500000

# include "libft.h"

typedef struct		s_liste
{
	int				fd;
	char			*string;
	struct s_liste	*next;
}					t_liste;

int					get_next_line(const int fd, char **line);

#endif
