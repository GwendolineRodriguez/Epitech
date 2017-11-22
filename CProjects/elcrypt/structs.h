/*
** structs.h for structs in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Fri Feb 27 22:23:23 2015 gwendoline rodriguez
** Last update Sun Mar  1 23:14:02 2015 gwendoline rodriguez
*/

#ifndef STRUCTS_H_
# define STRUCTS_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define UNUSED __attribute__((unused))

typedef struct	s_data
{
  int		crypt;
  char		*filesrc;
  char		*filedest;
  char		*key;
  int		check;
  char		*base;
  unsigned char	*res;
}		t_data;

typedef struct	s_file
{
  int           i;
  int           fd;
  int           ret;
  char          buffer[9];
  int           check;
}		t_file;

void            my_error(char *str);
void            my_parse1(char **av, t_data *p);
void            my_parse2(char **av, t_data *p);
int             parsing(char **av);
int             check_parse(char **av);
int		check_key(char *key, t_data *p);
int		choose_crypt(t_data *p, t_file *f);
int             my_get2base(char *key, t_data *p, int i);
int             my_get8base(char *key, t_data *p, int i);
int             my_get16base(char *key, t_data *p, int i);
int             my_send_file_by8(t_data *p, t_file *f);
int             my_put_str_tofile(unsigned char *src, char *dest);
long		my_strlen_long(char *str);
long		my_getnbr_base(char *str, char *base);
char		*convert_base(char *nbr, char *base_from,
			      char *base_to);
char		**tab_text(int *j, int *i, char *av,
			   char **oct);
char		*conv_text(char *tex, int i, int j, char *av);
char		*parity_bit(char *key_prim, char *key);
char		*rotate_key(char *key_prim);
char		*or_exc(char *dest, char *src);
int		my_exp(int val, int n);
unsigned char	*tr_ascii_r(char *mess_r, unsigned char *carac,
			    int i, int j);
void		all_turn(int *i, char *key_prim,
			  char *mess_l, char *mess_r);
unsigned char   *end_feistel(char *mess_r,
			     char *mess_l);
unsigned char	*feistel(char *text, char *key_prim);
unsigned char	*encrypt(t_data *p, t_file *f);
long		init(char *base, long *nbr, long *j, long *i);
long		check_neg(char *s);
long		check_base(char *base, long n);
unsigned char   *my_revstr_unsigned(unsigned char *str);
int		my_strlen_unsigned(unsigned char *str);

#endif /* STRUCTS_H_ */
