/*
** main.c for mastermind in /home/faure-_l/Colle/master_mind/lolo
** 
** Made by Loik Fauré-Berlinguette
** Login   <faure-_l@epitech.net>
** 
** Started on  Thu May 21 14:42:04 2015 Loik Fauré-Berlinguette
** Last update Thu May 21 15:12:32 2015 Loik Fauré-Berlinguette
*/

#include <unistd.h>
#include <sys/types.h>

int	loop()
{
  int	len;
  char	buffer[1080];

  while (42)
    {
      my_putstr("$> ");
      if ((len = read(0, buffer, 1080)) == -1)
	my_error("[ERROR] : Read Problem in 'loop()' ! \n");
      buffer[len] = '\0';
      //      manage_command(buffer);
    }
  return (0);
}

int	main()
{
  loop();
  return (0);
}
