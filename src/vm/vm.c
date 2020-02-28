/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:09:46 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/28 14:41:43 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void                    *initialize_map(t_player *players, int number)
{
    unsigned char   *arena;
    t_player        *temp;
    int             player_part;
    int             jumper;
    int             hopper;
    int             bubbler;

    // if (!(arena = malloc(MEM_SIZE)))
    //     ft_error("ARENA ALLOCATION ERROR");
    temp = NULL;
    if (!(arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE)))
        ft_error("ARENA ALLOCATION ERROR");
    temp = players;
    player_part = MEM_SIZE / number;
    jumper = 0;
    while (jumper < MEM_SIZE && temp)
    {
        hopper = jumper;
        bubbler = 0;
        while (bubbler < temp->exec_size)
        {
            ((unsigned char*)arena)[hopper] = temp->exec_code[bubbler];
            hopper++;
            bubbler++;
        }
        while (hopper < CHAMP_MAX_SIZE)
        {
            ((unsigned char*)arena)[hopper] = 0x0;
            hopper++;
        }
        temp = temp->next;
        jumper += player_part;
    }
    return (arena);
}

void                    *last_player(t_player *players)
{
    t_player    *temp;

    temp = players;
    while (temp->next)
        temp = temp->next;
    return (temp);
}

t_vm                    *init_vm(t_player *players)
{
    t_vm   *monitor;

    if (!(monitor = (t_vm*)malloc(sizeof(t_vm))))
        ft_error("MONITOR ALLOCATION ERROR");
    monitor->last_pl_alive = last_player(players);
    monitor->cycle_counter = 0;
    monitor->cycle_to_die = CYCLE_TO_DIE;
    monitor->prev_ctd_lives = 0;
    monitor->check_performed = 0;
    return (monitor);
}