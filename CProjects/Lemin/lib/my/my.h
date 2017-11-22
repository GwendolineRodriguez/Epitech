/*
** my.h for  in /home/daniel_b/Rendu/Piscine_C_J09/include
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Fri Oct 10 20:25:00 2014 Erwan DANIEL
** Last update Tue Apr  7 16:44:08 2015 DANIEL Erwan
*/

#ifndef MY_H_
#define MY_H_

void	my_free_double(char **foo);
void	my_addstrstr(char **str, char *add);
char	**my_parse_str(char *str, char key);
int	my_find_prime_sup(int nb);
int     my_getnbr_base(char *str, char *base);
int     my_getnbr(char *str);
int     my_isneg(int n);
int     my_power_rec(int nb, int power);
void	my_putchar(char c);
int     my_putnbr_base(int nb, char *base);
int     get_next(int number);
int     my_putstr(char *str);
char	*my_revstr(char *str);
int	my_showmem(char *str, int size);
int     my_showstr(char *str);
void    my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
char    *my_strcapitalize(char *str);
char    *my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *src);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int     my_str_islower(char *str);
int     my_strlcat(char *dest, char *src, int size);
int     my_strlen(char *str);
char    *my_strlowcase(char *str);
char    *my_strncat(char *dest, char *src, int nb);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(char *str, char *to_find);
int	my_strsize(char *str);
char    *my_strupcase(char *str);
int     my_swap(int *a, int *b);
int	my_printf(const char *format, ...);
char	**my_str_to_wordtab(char *str);
void	*my_malloc(int size);
char	*my_strdup(char *str);
int	str_not_empty(char *str);

#endif
