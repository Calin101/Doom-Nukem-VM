/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:55:02 by beduroul          #+#    #+#             */
/*   Updated: 2020/06/27 14:00:16 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb >= 13)
		return (0);
	nb = nb * ft_factorial(nb - 1);
	return (nb);
}
