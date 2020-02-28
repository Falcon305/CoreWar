/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:53:47 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/28 17:44:48 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include <stdio.h>
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define FALSE 0
# define TRUE 1

typedef enum            e_regs {
                        r1, r2,
                        r3, r4,
                        r5, r6,
                        r7, r8,
                        r9, r10,
                        r11, r12,
                        r13, r14,
                        r15, OP
}                       t_regs;

typedef struct          s_op
{
    char    *name;
}                       t_op;

typedef struct          s_player
{
    int                 id;
    void                *name;
    char                *comment;
    int                 exec_size;
    unsigned char       *exec_code;
    struct s_player     *next;
    struct s_player     *prev;
    
}                       t_player;

typedef struct          s_cursor
{
    int                 id;
    int                 carry;
    void                *current_op;
    int                 last_live_performed;
    int                 cycle_before_exec;
    int                 bytes_to_next_op;
    void                *registers;
    struct s_process    *next;
}                       t_cursor;

typedef struct          s_vm
{
    unsigned char       *arena;
    void                *last_pl_alive;
    int                 cycle_counter;
    int                 cycle_to_die;
    int                 prev_ctd_lives;
    int                 program_counter;
    int                 check_performed;
}                       t_vm;

/*
** ----------------------------------------------------------------------------
** 						  	Parsing functions
** ----------------------------------------------------------------------------
*/
unsigned int            ft_read_file(int fd, size_t size);
int                     check_0x0(int fd);
void                    parse_header(int fd);
void                    *parse_name(int fd);
void                    *parse_comment(int fd);
void                    *parse_exec(int fd, int exec_size);
t_player                *parse_players(char **argv, int argc, int *number);
/*
** ----------------------------------------------------------------------------
** 						  	VM functions
** ----------------------------------------------------------------------------
*/
void                    *initialize_map(t_player *players, int number);
t_vm                    *init_vm(t_player *players);
void                    *last_player(t_player *players);
/*
** ----------------------------------------------------------------------------
** 						  	Cursor functions
** ----------------------------------------------------------------------------
*/
t_cursor                *make_cursor(void);
t_queue                 *make_affect_cursor(void *arena, t_player   *players);
/*
** ----------------------------------------------------------------------------
** 						  	Debugging functions
** ----------------------------------------------------------------------------
*/
void                    DB_show_players(t_player *player, int norm_rev);
void                    DB_show_vm(t_vm *vm);
void	                DB_show_arena(unsigned char *arena);


/*typedef struct          s_op
{
    uint8_t             code;
    char                *name;
    int                 args_num;
    int                 type;
    uint8_t             types[3];
    int                 carry_modif;
    uint8_t             t_dir_size;
    uint32_t            cycles;
}                       t_op;

static t_op                    op_tab[17]
{
    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x02,
        .name = "ld",
        .args_num = 2,
        .type = 1;
        .types = {T_DIR | T_IND, T_REG, 0},
        .carry_modif = 1,
        .t_dir_size = 4,
        .cycles = 5,
    },
    
    {
        .code = 0x03,
        .name = "st",
        .args_num = 2,
        .type = 1;
        .types = {T_REG, T_REG | T_IND, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 5,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },

    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = 0;
        .types = {T_DIR, 0, 0},
        .carry_modif = 0,
        .t_dir_size = 4,
        .cycles = 10,
    },
};*/

#endif