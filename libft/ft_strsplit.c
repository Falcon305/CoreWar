/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:31:48 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/09 13:26:34 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		detect_delim(char const s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int		w_lenght(char *s, char c)
{
	int		size;

	while (*s)
	{
		if (!detect_delim(*s, c))
			break ;
		++s;
	}
	size = 0;
	while (*s)
	{
		if (detect_delim(*s, c))
			break ;
		++size;
		++s;
	}
	return (size - 1);
}

static int		w_count(char *str, char c)
{
	int		size;

	size = 0;
	while (*str)
	{
		while (!detect_delim(*str, c) && *str)
			++str;
		++size;
		while (detect_delim(*str, c) && *str)
			++str;
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**word;
	int		w_nbr;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (detect_delim(*s, c))
		++s;
	w_nbr = w_count((char*)s, c);
	if (!(word = (char **)malloc(sizeof(char *) * (w_nbr + 1))))
		return (NULL);
	while (i < w_nbr)
	{
		size = w_lenght((char*)s, c) + 1;
		if (!(word[i] = (char *)malloc(sizeof(char) * size)))
			return (NULL);
		ft_strncpy(word[i], s, size);
		s += size;
		while (detect_delim(*s, c))
			++s;
		++i;
	}
	word[i] = 0;
	return (word);
}
