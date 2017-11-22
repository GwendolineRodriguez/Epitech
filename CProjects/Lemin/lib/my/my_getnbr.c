/*
** my_getnbr for  in /home/daniel_b/Piscine_C_J04
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Oct  2 20:15:40 2014 Erwan DANIEL
** Last update Sun Feb  1 19:36:48 2015 DANIEL Erwan
*/

int	extract_number(char *str, int is_neg)
{
  int	counter;
  int	output;

  counter = 0;
  output = 0;
  if (is_neg > -1)
    {
      while (*str >= 48 && *str <= 48 + 9 && counter <= 10)
        {
          output = output + (*str - 48);
          output = output * 10;
          counter = counter + 1;
          str = str + sizeof (char);
        }
      output = output / 10;
      if (is_neg == 1)
        output = output * -1;
    }
  return (output);
}

int	my_getnbr(char *str)
{
  int	counter;
  int	is_neg;
  int	output;
  char	character;

  output = 0;
  counter = 0;
  is_neg = -1;
  while (*str != '\0')
    {
      if (*str >= '0' && *str <= '9')
	{
	  str = str - sizeof (char);
	  if (*str  == '-')
	    is_neg = 1;
	  else
	    is_neg = 0;
	  str = str + sizeof (char);
	  break;
	}
      str = str + sizeof (char);
    }
  output = 0;
  output += extract_number(str, is_neg);
  return (output);
}
