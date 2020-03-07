/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:53:47 by hrazani           #+#    #+#             */
/*   Updated: 2020/03/03 19:00:37 by hrazani          ###   ########.fr       */
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
    uint8_t             code;
    char                *name;
    int                 args_num;
    int                 type;
    uint8_t             types[3];
    int                 carry_modif;
    uint8_t             t_dir_size;
    uint32_t            cycles;
}                       t_op;

typedef struct			s_stack
{
	int					data;
	struct s_stack		*next;
}						t_stack;

static t_op						op_tab[16] =  {
    {
        .code = 0x01,
        .name = "live",
        .args_num = 1,
        .type = FALSE,
        .types = {T_DIR, 0, 0},
        .carry_modif = FALSE,
        .t_dir_size = 4,
        .cycles = 10,
    },
    {
        .code = 0x02,
        .name = "ld",
        .args_num = 2,
        .type = 1,
        .types = {T_DIR | T_IND, T_REG, 0},
        .carry_modif = TRUE,
        .t_dir_size = 4,
        .cycles = 5,
    },
    {
        .code = 0x03,
        .name = "st",
        .args_num = 2,
        .type = TRUE,
        .types = {T_REG, T_REG | T_IND, 0},
        .carry_modif = FALSE,
        .t_dir_size = 4,
        .cycles = 5,
    },
    {
        .code = 0x04,
        .name = "add",
        .args_num = 3,
        .type = TRUE,
        .types = {T_REG, T_REG, T_REG},
        .carry_modif = TRUE,
        .t_dir_size = 4,
        .cycles = 10,
    },
    {
        .code = 0x05,
        .name = "sub",
        .args_num = 3,
        .type = TRUE,
        .types = {T_REG, T_REG, T_REG},
        .carry_modif = TRUE,
        .t_dir_size = 4,
        .cycles = 10,
    },
    {
        .code = 0x06,
        .name = "and",
        .args_num = 3,
        .type = TRUE,
        .types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
        .carry_modif = TRUE,
        .t_dir_size = 4,
        .cycles = 6,
    },
    {
        .code = 0x07,
        .name = "or",
        .args_num = 3,
        .type = TRUE,
        .types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
        .carry_modif = TRUE,
        .t_dir_size = 4,
        .cycles = 6,
    },
    {
        .code = 0x08,
        .name = "xor",
        .args_num = 1,
        .type = TRUE,
        .types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
        .carry_modif = TRUE,
        .t_dir_size = 4,
        .cycles = 6,
    },
    {
        .code = 0x09,
        .name = "zjmp",
        .args_num = 1,
        .type = FALSE,
        .types = {T_DIR, 0, 0},
        .carry_modif = FALSE,
        .t_dir_size = 2,
        .cycles = 20,
    },
    {
        .code = 0x0a,
        .name = "ldi",
        .args_num = 3,
        .type = TRUE,
        .types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
        .carry_modif = FALSE,
        .t_dir_size = 2,
        .cycles = 25,
    },
    {
        .code = 0x0b,
        .name = "sti",
        .args_num = 3,
        .type = TRUE,
        .types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
        .carry_modif = FALSE,
        .t_dir_size = 2,
        .cycles = 25,
    },
    {
        .code = 0x0c,
        .name = "fork",
        .args_num = 1,
        .type = FALSE,
        .types = {T_REG, 0, 0},
        .carry_modif = FALSE,
        .t_dir_size = 2,
        .cycles = 800,
    },
    {
        .code = 0x0d,
        .name = "lld",
        .args_num = 2,
        .type = TRUE,
        .types = {T_DIR | T_IND, T_REG, 0},
        .carry_modif = TRUE,
        .t_dir_size = 4,
        .cycles = 10,
    },
    {
        .code = 0x0e,
        .name = "lldi",
        .args_num = TRUE,
        .type = 0,
        .types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
        .carry_modif = TRUE,
        .t_dir_size = 2,
        .cycles = 50,
    },
    {
        .code = 0x0f,
        .name = "lfork",
        .args_num = 1,
        .type = FALSE,
        .types = {T_DIR, 0, 0},
        .carry_modif = FALSE,
        .t_dir_size = 2,
        .cycles = 1000,
    },
    {
        .code = 0x10,
        .name = "aff",
        .args_num = 1,
        .type = TRUE,
        .types = {T_REG, 0, 0},
        .carry_modif = FALSE,
        .t_dir_size = 4,
        .cycles = 2,
    },
};

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
** 						  	Stack functions
** ----------------------------------------------------------------------------
*/
void					init_stack(t_stack *head);
t_stack					*push(t_stack *head, int data);
t_stack					*pop(t_stack *head, int *element);
int						empty(t_stack *head);
int						stack_len(t_stack *path);
void		            free_stack(t_stack *stack);
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

#endif