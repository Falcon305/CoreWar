/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 02:42:56 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/15 02:53:13 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(const char *word)
{
	int		count;
	int		len;
	int		i;
	char	last;

	count = 0;
	len = ft_strlen(word);
	if (len > 0)
	{
		last = word[0];
	}
	i = 0;
	while (i <= len)
	{
		if ((word[i] == ' ' || word[i] == '\0') && last != ' ')
		{
			count++;
		}
		last = word[i];
		i++;
	}
	return (count);
}
