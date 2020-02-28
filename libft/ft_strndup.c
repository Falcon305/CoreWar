/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 22:55:06 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/14 23:18:51 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char *cpy;

	cpy = NULL;
	cpy = (char *)malloc(sizeof(char) * (n + 1));
	if (cpy != NULL)
		ft_strncpy(cpy, s1, n);
	return (cpy);
}
