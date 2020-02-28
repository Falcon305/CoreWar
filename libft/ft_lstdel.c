/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:33:59 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/11 16:51:52 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cont;

	if (*alst)
	{
		while (*alst)
		{
			cont = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = cont;
		}
	}
}
