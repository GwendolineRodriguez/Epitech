/*
** fill_grid.c for my_mixword in /home/duclos_r/Tek-1/Colle/my_mixword
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Wed Jun 10 09:26:58 2015 Rémi Duclos
** Last update Wed Jun 10 15:01:23 2015 
*/

#include "my_mixword.h"

void	get_grid(char *file, t_grid *grid)
{
  char	buffer[4096];
  char	**wordtab;
  int	fd;
  int	rd;

  fd = open(file , O_RDONLY);
  if (fd < 0)
    exit(0);
  rd = read(fd, buffer, 4095);
  if (rd < 0)
    exit(0);
  buffer[rd] = '\0';
  wordtab = str_to_wordtab(buffer, '\n');
  if (wordtab == NULL)
    exit(0);
  fill_grid(wordtab, grid);
}

void	fill_grid(char **wordtab, t_grid *grid)
{
  int	way;

  grid->grid = malloc(sizeof(char *) * (grid->size + 1));
  if (grid->grid == NULL)
    exit(0);
  grid->grid[0] = my_strdup("adrow");
  grid->grid[1] = my_strdup("tyuoo");
  grid->grid[2] = my_strdup("ddrdr");
  grid->grid[3] = my_strdup("wdwed");
  grid->grid[4] = my_strdup("cdxcb");
  grid->grid[5] = NULL;
}
