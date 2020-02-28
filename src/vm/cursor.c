/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:11:22 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/28 15:16:34 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_cursor                    *make_cursor(void)
{
    t_cursor   *cursor;
    static int  id;
    //t_regs      regs;

    if (!(cursor = (t_cursor*)malloc(sizeof(t_cursor))))
        ft_error("cursor ALLOCATION ERROR");
    cursor->id = id;
    cursor->carry = FALSE;
    cursor->current_op = NULL;
    cursor->last_live_performed = 0;
    cursor->cycle_before_exec = 0;
    cursor->bytes_to_next_op = 0;
    cursor->registers = malloc(REG_NUMBER * REG_SIZE);
    cursor->next = NULL;
    id++;
    return (cursor);
}

t_queue     *make_affect_cursor(void *arena, t_player *players)
{
    t_queue     *queue;
    t_player    *temp;
    t_cursor   *cursor;
    int         jumper;

    temp = players;
    queue = ft_new_queue();
    jumper = 0;
    while (temp)
    {
        cursor = make_cursor();
        cursor->current_op = arena;
        ft_enque(queue, cursor);
       /*
        * printf("%x", ((int*)cursor->current_op)[0] << 8 | ((int*)cursor->current_op)[1]);
        * exit(120);
        */

       temp = temp->next;
    }
    return (NULL);
}