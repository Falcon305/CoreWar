/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:54:47 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/27 19:59:03 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

/*
 *              Read size bytes from the given file descriptor.
 */

unsigned int            ft_read_file(int fd, size_t size)
{
    char            data[size];
    unsigned int    jumper;
    unsigned int    result;
    
    jumper = -1;
    result = 0;
    if (!(read(fd,&data, size) > 0))
        return (0);
    while (++jumper < size)
        result = result << 8 | (data[jumper] & 0xff);
    return (result);
}

int                     check_0x0(int fd)
{
    if (!ft_read_file(fd, 4))
        return (1);
    return (0);
}