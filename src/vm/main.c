/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:20:21 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/28 17:06:26 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int     main(int argc, char **argv)
{
    t_player    *players;
    t_vm        *vm;
    t_queue     *queue;
    int         players_number;
    t_player    *temp;
    
    players_number = 0;
    players = parse_players(argv, argc, &players_number);
    vm = init_vm(players);
    vm->arena = initialize_map(players, players_number);
    queue = make_affect_cursor(vm->arena, players);
    temp = last_player(players);
    DB_show_arena(vm->arena);
    DB_show_vm(vm);
    DB_show_players(players, argc);
    return (0);
}