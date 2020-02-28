/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:35:04 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/14 23:08:44 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr1;
	const char	*ptr2;

	ptr1 = (char *)dst;
	ptr2 = (const char *)src;
	if (src >= dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		ptr1 += len;
		ptr2 += len;
		while (len--)
			*(--ptr1) = *(--ptr2);
	}
	return (dst);
}
