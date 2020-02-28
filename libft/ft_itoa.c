/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:58:07 by hrazani           #+#    #+#             */
/*   Updated: 2018/11/14 15:45:48 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_itoa_len(int n)
{
	size_t	ret;

	if (n == 0)
		return (1);
	ret = 0;
	if (n < 0)
		ret++;
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char				*ft_itoa(int n)
{
	size_t	l;
	size_t	e;
	char	*ret;

	l = ft_itoa_len(n);
	if (!(ret = (char *)malloc(l + 1)))
		return (NULL);
	ret[l] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		e = 1;
	}
	else
		e = 0;
	while (l-- > e)
	{
		ret[l] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (ret);
}
