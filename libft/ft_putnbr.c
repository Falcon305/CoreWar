/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:30:01 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/08 22:18:07 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	numr;

	if (n < 0)
	{
		ft_putchar('-');
		numr = n * -1;
	}
	else
		numr = n;
	if (numr >= 10)
		ft_putnbr(numr / 10);
	ft_putchar(numr % 10 + 48);
}
