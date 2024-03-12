/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:10:21 by tkurukay          #+#    #+#             */
/*   Updated: 2023/12/15 15:37:11 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cal_digit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		i;
	long	x;

	i = ft_cal_digit(num);
	x = num;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		x = -x;
		str[0] = '-';
	}
	while (x)
	{
		str[--i] = x % 10 + '0';
		x /= 10;
	}
	return (str);
}
