/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:43:44 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/28 17:44:32 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void                    parse_header(int fd)
{
    unsigned int result;

    result = ft_read_file(fd, 4);
    if (result != COREWAR_EXEC_MAGIC)
        ft_error("BAD HEADER !");
}

void                    *parse_name(int fd)
{
    int     jumper;
    void    *champ_name;
    
    if (!(champ_name = malloc(PROG_NAME_LENGTH)))
        ft_error("NAME ALLOCATION ERROR");
    jumper = 0;
    while (jumper < PROG_NAME_LENGTH)
    {
        ((char*)champ_name)[jumper] = ft_read_file(fd, 1);
        jumper++;
    }
    if (!check_0x0(fd))
        ft_error("NAME DONT END WITH 0x0");
    return (champ_name);
}

void                    *parse_comment(int fd)
{
    void    *champ_comment;
    int     jumper;

    champ_comment = ft_strnew(COMMENT_LENGTH);
    jumper = 0;
    while (jumper < COMMENT_LENGTH)
    {
        ((char*)champ_comment)[jumper] = ft_read_file(fd, 1);
        jumper++;
    }
    return (champ_comment);
}

void                    *parse_exec(int fd, int exec_size)
{
    unsigned char     *champ_exec;
    int     jumper;

    champ_exec = (unsigned char *)malloc(sizeof(unsigned char) * exec_size);
    jumper = -1;
    while (++jumper < CHAMP_MAX_SIZE && jumper < exec_size)
        champ_exec[jumper] = ft_read_file(fd, 1);
    if (jumper != exec_size)
        ft_error("Error player executable size dont matche \
                the real player size");
    return (champ_exec);
}