/*
** prerequis.c for prerequis in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 24 11:12:21 2015 
** Last update Wed Jun 24 12:08:48 2015 
*/

char	*my_strcapitalize_synthese(char *str)
{
  int	i;

  i = 1;
  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] = str[0] - 32;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a' && str[i] <= 'z')
          && (!(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
	  && (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
	  && (!(str[i - 1] >= '0' && str[i - 1] <= '9')))
        str[i] = str[i] - 32;
      else if ((str[i] >= 'A' && str[i] <= 'Z')
               && ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
      		   || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
		   || (str[i - 1] >= '0' && str[i - 1] <= '9')))
        str[i] = str[i] + 32;
      i++;
    }
  return (str);
}
