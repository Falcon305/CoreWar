/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:57:10 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/28 17:45:57 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_error(char *error_msg)
{
	char *p;

	p = RED("ERROR : ");
	while (*p)
		write(2, p++, 1);
	p = error_msg;
	while (*p)
		write(2, p++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
