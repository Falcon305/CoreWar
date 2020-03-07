/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:07:27 by hrazani           #+#    #+#             */
/*   Updated: 2020/03/01 15:04:28 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_player                   *parse_players(char **argv, int argc, int *number)
{
    int         i;
    t_player    *player;
    t_player    *temp;
    int         fd;

    if (argc > 5 || argc < 2)
        ft_error("INCORRECT NUMBER OF ARGUMENT");
    i = 0;
    if (!(player = (t_player*)malloc(sizeof(t_player))))
        ft_error("ALLOCATION ERROR");
    player->id = 1;
    player->prev = NULL;
    temp = player;
    while (++i < argc)
    {
        fd = open(argv[i], O_RDONLY);
        parse_header(fd);
        temp->id = i;
        (*number)++;
        temp->name = parse_name(fd);
        temp->exec_size = ft_read_file(fd, 4);
        temp->comment = parse_comment(fd);
        if (!check_0x0(fd))
            ft_error("COMMENT DONT END WITH 0x0");
        temp->exec_code = parse_exec(fd, temp->exec_size);
        if (i + 1 < argc)
        {
            if (!(temp->next = (t_player*)malloc(sizeof(t_player))))
                ft_error("ALLOCATION ERROR");
            temp->next->prev  = temp;
        }
        else
        {
            temp->next = NULL;
            break ;
        }
        temp = temp->next;
    }
    return (player);
}