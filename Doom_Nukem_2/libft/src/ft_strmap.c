/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:22:43 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:04:12 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s)
	{
		i = ft_strlen((char *)s);
		if (!(str = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		ft_strcpy(str, (char *)s);
		while (str[i])
		{
			str[i] = (*f)(str[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
