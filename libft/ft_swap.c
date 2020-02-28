/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 11:53:15 by hrazani           #+#    #+#             */
/*   Updated: 2019/05/05 11:53:51 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}