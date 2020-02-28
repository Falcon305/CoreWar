/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:28:18 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/13 23:47:23 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *tr;

	tr = (t_btree*)malloc(sizeof(t_btree));
	if (!tr)
		return (NULL);
	tr->item = item;
	tr->right = 0;
	tr->left = 0;
	return (tr);
}
