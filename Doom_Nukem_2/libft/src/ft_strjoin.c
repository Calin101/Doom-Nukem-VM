/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:07:04 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:03:56 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;

	if (s1 && s2)
	{
		if (!s1 && !s2)
			return (NULL);
		if (!s1)
			return (ft_strdup(s2));
		if (!s2)
			return (ft_strdup(s1));
		if (!(s3 = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2))))
			return (NULL);
		ft_strcpy(s3, (char *)s1);
		ft_strcat(s3, (char *)s2);
		return (s3);
	}
	return (NULL);
}
