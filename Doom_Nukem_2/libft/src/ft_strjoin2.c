/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:46:47 by calin             #+#    #+#             */
/*   Updated: 2020/06/27 14:04:01 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin2(char const *s1, char const *s2, int index_free)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((dest = (char *)malloc(sizeof(*dest) *
	((ft_strlen(s1) + ft_strlen(s2)) + 1))) == NULL)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	if (index_free == 0)
		return (dest);
	if (index_free == 1 || index_free == 3)
		free((char *)s1);
	if (index_free == 2 || index_free == 3)
		free((char *)s2);
	return (dest);
}
