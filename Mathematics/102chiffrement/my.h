/*
** my.h for my.h in /home/rodrig_1/rendu/Maths/102chiffrement
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Nov 26 14:56:17 2014 gwendoline rodriguez
** Last update Thu Nov 27 10:00:18 2014 gwendoline rodriguez
*/

#ifndef MY_H_
# define MY_H_

int     *my_matrice(char *str, int i);
int     *reverskey(int *key);
char    convert_base(int matrice, char *base);
char    *encrypt(char *str, int *key, char *base, int i);
char	**my_str_to_wordtab(char *str);

#endif /* !MY_H_ */
