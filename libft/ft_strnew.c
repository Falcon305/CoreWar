/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:43:24 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/07 19:05:14 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*var;
	char	*var2;

	var = (char*)malloc((size + 1) * sizeof(char));
	if (var == NULL)
		return (NULL);
	var2 = var;
	while (size)
	{
		*var2++ = '\0';
		size--;
	}
	*var2 = '\0';
	ft_bzero(var, size);
	return (var);
}
