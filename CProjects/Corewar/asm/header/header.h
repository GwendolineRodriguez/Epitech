/*
** header.h for header in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/rodrig_1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Thu Mar  5 19:20:53 2015 gwendoline rodriguez
** Last update Sun Apr 12 21:21:44 2015 gwendoline rodriguez
*/

#ifndef HEADER_H_
# define HEADER_H_

#define READ_MAX 4096

typedef struct  s_tab
{
  int           nb_line;
}               t_tab;

int             my_putinstruct_tofile(char *dest, char **src);
int             my_putinstruct_tochar(char **tab, int fd);
int		my_putchar_tohexa(char *src, int fd);
int             my_putchar_tohexa2(char dest, char *src);
int             get_byte(int pos, int bin);
int             my_error(char *str);
int		check_arg(char *str);
int		display_map(char **map);
int		browse_file(int fd);
char		**get_file(char *file, t_tab *t);
void            get_register_nb(char **tab, int fd, int i);
void            get_direct(char **tab, int fd, int i);
void            get_indirect(char **tab, int fd, int i);
int             put_params_inhexa(char **tab, int fd);
void            put_magic_key(int fd);
int             get_len_param(char **tab, int p);
void            put_param(char **tab, int fd, int p);
int             put_header_tofile(char *dest, char **tab);
char            **get_clean_line(char *str);
int             strlen_char(char *str);
int             cpt_word(char *str);
int             check_if_point(char *str, int i);
int             check_if_label(char *str);
int		check_file(char *name_file);
int		brows_file(int fd);
int		count_separator(char *line);
int		line_correct_syntaxe(char *line);
int		line_correct(int i, int label);
int		analyse_extend(char *line);
int		analyse_instruction(char *line, int fd);
int		analyse_comment(char *line);
int		analyse_name(char *line);
int		find_add_sub_and_or_xor(char *line);
int		find_ld_st_lld_lldi(char *line);
int		find_live_zjmp_fork_lfork_aff(char *line);

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "op.h"

#endif /* HEADER_H_ */
