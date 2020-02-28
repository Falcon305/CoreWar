/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:48:03 by hrazani           #+#    #+#             */
/*   Updated: 2019/05/04 08:43:42 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strnumbers(const char *str)
{
	int i;

	i = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
		i++;
	return (i);
}

static int		count_n(char const *str)
{
	int n;

	n = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str - '0');
		else
			break ;
		str++;
	}
	return (n);
}

int				ft_atoi(const char *str)
{
	int		n;
	int		sign;
	int		j;

	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r' ||
			*str == '\n' || *str == '\f')
		str++;
	sign = *str == '-' ? -1 : 1;
	if (sign == -1 || *str == '+')
		str++;
	j = ft_strnumbers(str);
	n = count_n(str);
	if (j > 10)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return (n * sign);
}
