/*
** my_strstr for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Mon Oct  6 20:27:34 2014 Erwan DANIEL
** Last update Sun Feb  1 19:45:21 2015 DANIEL Erwan
*/

char	*my_strstr(char *str, char *to_find)
{

  int	i;

  if (str[0] != '\0')
    {
      i = 0;
      while (to_find[i] != '\0')
	{
	  if (to_find[i] != str[i])
	    return (my_strstr(str + 1, to_find));
	  i = i + 1;
	}
      return (str);
    }
  else
    return (0);
}
