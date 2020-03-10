/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:11:22 by hrazani           #+#    #+#             */
/*   Updated: 2020/03/10 19:48:50 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"



t_cursor                    *make_cursor(void)
{
    t_cursor   *cursor;
    static int  id;
    
    if (!(cursor = (t_cursor*)malloc(sizeof(t_cursor))))
        ft_error("CURSOR ALLOCATION ERROR");
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
    t_queue     *queue; // Stack Or Queue ??
    t_stack     *stack;
    t_player    *temp;
    t_cursor   *cursor;
    int         jumper;

    temp = players;
    init_stack(stack);
    queue = ft_new_queue();
    jumper = 0;
    while (temp)
    {
        cursor = make_cursor();
        cursor->current_op = arena;
        ft_enque(queue, cursor);
        printf(" ID = %d\n", cursor->id);
       temp = temp->next;
    }
    return (NULL);
}