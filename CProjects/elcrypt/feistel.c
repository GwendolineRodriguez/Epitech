/*
** feistel.c for feistel in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sun Mar  1 20:45:12 2015 gwendoline rodriguez
** Last update Sun Mar  1 23:17:18 2015 gwendoline rodriguez
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "my.h"

unsigned char           *tr_ascii_r(char *mess_r, unsigned char *carac,
				    int i, int j)
{
  int                   k;
  int                   res;
  int                   val;

  k = 0;
  res = 0;
  while (i >= 0)
    {
      if (mess_r[i] == '0')
	val = 0;
      else        val = 1;
      res = res + (val * my_exp(2, j));
      if (j == 7)
	{
	  carac[k++] = res;
	  j = -1;
	  res = 0;
	}
      j++;
      i--;
    }
  return (carac);
}

void                    all_turn(int *i, char *key_prim,
				 char *mess_l, char *mess_r)
{
  char                  *keysec;
  int                   j;

  if ((keysec = malloc(sizeof(char) * 33)) == NULL)
    exit(0);
  if (*i != 0)
    key_prim = rotate_key(key_prim);
  j = 24;
  while (key_prim[j] != '\0')
    {
      keysec[j - 24] = key_prim[j];
      j = j + 1;
    }
  keysec[32] = '\0';
  if (*i % 2 == 0)
    {
      mess_r = or_exc(mess_r, keysec);
      mess_l = or_exc(mess_l, mess_r);
    }
  else    {
    mess_l = or_exc(mess_l, keysec);
    mess_r = or_exc(mess_r, mess_l);
  }
  (*i)++;
}

unsigned char           *end_feistel(char *mess_r, char *mess_l)
{
  unsigned char         *cara;
  unsigned char         *cara2;

  if ((cara = malloc(sizeof(cara) * 9)) == NULL)
    exit(0);
  if ((cara2 = malloc(sizeof(cara) * 9)) == NULL)
    exit(0);
  cara = tr_ascii_r(mess_r, cara, 31, 0);
  cara2 = tr_ascii_r(mess_l, cara2 + 4, 31, 0);
  cara[4] = cara2[0];
  cara[5] = cara2[1];
  cara[6] = cara2[2];
  cara[7] = cara2[3];
  cara[8] = '\0';
  cara = my_revstr_unsigned(cara);
  return (cara);
}

unsigned char           *feistel(char *text, char *key_prim)
{
  char                  *mess_l;
  char                  *mess_r;
  int                   i;

  i = 0;
  if ((mess_r = malloc(sizeof(char) * 33)) == NULL)
    exit(0);
  if ((mess_l = malloc(sizeof(char) * 33)) == NULL)
    exit(0);
  while (text[i] != '\0')
    {
      if (i < 32)
	mess_r[i] = text[i];
      else        mess_l[i - 32] = text[i];
      i++;
    }
  mess_r[32] = '\0';
  mess_l[32] = '\0';
  i = 0;
  while (i < 8)
    all_turn(&i, key_prim, mess_l, mess_r);
  return (end_feistel(mess_r, mess_l));
}

unsigned char           *encrypt(t_data *p, t_file *f)
{
  char                  *key_prim;
  long                  i;
  char                  *text;

  i = 0;
  if ((key_prim = malloc(sizeof(char) * 57)) == NULL)
    exit(0);
  if ((text = malloc(sizeof(char) * 65)) == NULL)
    exit(0);
  while (i < 65)
    text[i++] = '\0';
  p->key = convert_base(p->key, p->base, "01");
  text = conv_text(text, 0, 0, f->buffer);
  key_prim = parity_bit(key_prim, p->key);
  return (feistel(text, key_prim));
}
