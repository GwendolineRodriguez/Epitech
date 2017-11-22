/*
** my.h for my in /home/RODRIG_1/rendu/Piscine_C_J09/include
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  9 14:15:29 2014 rodriguez gwendoline
** Last update Thu Oct  9 15:21:55 2014 rodriguez gwendoline
*/

#ifndef __MY_H__
#define __MY_H__

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_isneg(int nb);
int     my_strlen(char *str);
int     my_getnbr(char *str);
int     my_power_rec(int nb, int power);
int     my_square_root(int nb);
int     my_is_prime(int nombre);
int     my_find_prime_sup(int nb);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int nb);
int     my_str_isalpha(char *str);
int     my_str_isnum(char *str);
int     my_str_islower(char *str);
int     my_str_isupper(char *str);
int     my_str_isprintable(char *str);
int     my_showstr(char *str);
int     my_showmem(char *str, int size);
int	*my_strlcat(char *dest, char *src, int size);
char    *my_strcpy(char *dest, char *src);
char    *my_strncpy(char *dest, char *src, int nb);
char    *my_revstr(char *str);
char    *my_strstr(char *str, char *to_find);
char    *my_strupcase(char *str);
char    *my_strlowcase(char *str);
char    *my_strcapitalize(char *str);
char    *my_strcat(char *dest, char *src);
char    *my_strncat(char *dest, char *src, int nb);

#endif __MY_H__
