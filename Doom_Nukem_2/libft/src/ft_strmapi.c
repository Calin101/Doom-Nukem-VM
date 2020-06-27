/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:03:53 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:04:14 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			str[i] = (*f)(i, str[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
