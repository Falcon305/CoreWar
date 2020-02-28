/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:25:50 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/12 19:12:58 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		detect_separator(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	char	*ptr;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	if (size == 0)
	{
		ret = (char *)malloc(1 * sizeof(char));
		return (ret);
	}
	while (detect_separator(*s))
		s++;
	size = ft_strlen((char *)s);
	ptr = (char *)s + size - 1;
	while (ptr > s && (detect_separator(*ptr)))
		ptr--;
	size = (ptr - s) + 1;
	ret = (char *)malloc((size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, s, size);
	*(ret + size) = '\0';
	return (ret);
}
