/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:15:52 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/28 17:05:52 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void    DB_show_players(t_player *player, int norm_rev)
{
    int jumper;
    t_player    *temp;

    if (norm_rev == 1)
        temp = last_player(player);
    temp = norm_rev == 1 ? last_player(player) : player;
    while (player)
    {
        printf("Player id : %d\nPlayer name : %s\nPlayer comment : %s\nPlayer size : %d\n",
            player->id, (char*)player->name, player->comment, player->exec_size);
        jumper = 0;
        while (jumper < player->exec_size)
        {
            printf("%02hhx", player->exec_code[jumper]);
            jumper++;  
        }
        printf("\n\n\n");
        if (norm_rev == 1)
            player = player->prev;
        else
            player = player->next;
    }
}

void	DB_show_arena(unsigned char *arena)
{
	int	i;
	int	address;

	i = 0;
	address = 0;
	while (i < 4096)
	{
		if (i != 0 && i % 64 == 0)
			printf("%#06x : ", address);
		else if (i == 0)
			printf("0x0000 : ");
		printf("%02hhx ", arena[i]);
		if (i != 0 && (i + 1) % 64 == 0)
		{
			printf("\n");
			address = address + 64;
		}
		i++;
	}
}

void    DB_show_vm(t_vm *vm)
{
    printf("Last player alive : %s\n", ((t_player*)vm->last_pl_alive)->name);
    printf("Cylces sum : %d\n", vm->cycle_counter);
    printf("Cycle to die : %d\n", vm->cycle_to_die);
    printf("Live perforned last cycle to die : %d\n", vm->prev_ctd_lives);
    printf("Checks performed : %d\n", vm->check_performed);
    ft_putendl("\n");
}