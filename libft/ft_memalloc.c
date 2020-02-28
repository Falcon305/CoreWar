/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_memalloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:04:32 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/07 17:28:26 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*var;

	var = (void*)malloc(sizeof(void*) * size);
	if (var == NULL)
		return (NULL);
	ft_bzero(var, size);
	return (var);
}
