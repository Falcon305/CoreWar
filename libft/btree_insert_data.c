/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:46:02 by hrazani           #+#    #+#             */
/*   Updated: 2018/10/15 04:29:34 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *tr;

	tr = *root;
	if (!tr)
	{
		*root = btree_create_node(item);
	}
	else if (cmpf(item, tr->item) >= 0)
	{
		btree_insert_data(&tr->right, item, cmpf);
	}
	else
	{
		btree_insert_data(&tr->left, item, cmpf);
	}
}
