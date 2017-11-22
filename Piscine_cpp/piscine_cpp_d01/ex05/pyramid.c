/*
** pyramid.c for pyramid in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d01/ex05
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jan  6 20:42:27 2016 Gwendoline Rodriguez
** Last update Wed Jan  6 22:37:34 2016 Gwendoline Rodriguez
*/

int	get_min(int x, int y)
{
  if (x < y)
    return (x);
  return (y);
}

int	recursiv_search(int size, int **map, int x, int y)
{
  if (x == size - 1)
    return (get_min(map[x][y], map[x][y + 1]));
  return (get_min(recursiv_search(size, map, x + 1, y),
		  recursiv_search(size, map, x + 1, y + 1)) + map[x][y]);
}

int	pyramid_path(int size, int **map)
{
  return (recursiv_search(size, map, 0, 0));
}

/* int	main() */
/* { */
/*   int **tab = tab[5][5]; */
/*   tab = { */
/* 	{0}, */
/* 	{7, 4}, */
/* 	{2, 3, 6}, */
/* 	{8, 5, 9, 3} */
/* 	}; */
/*   pyramid_path(4, tab); */
/*   return (0); */
/* } */
