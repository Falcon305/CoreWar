/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 21:22:55 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/14 21:51:28 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*prv;
	t_list	*cur;
	t_list	*next;

	prv = NULL;
	cur = *alst;
	while (cur)
	{
		next = cur->next;
		cur->next = prv;
		prv = cur;
		cur = next;
	}
	*alst = prv;
}
