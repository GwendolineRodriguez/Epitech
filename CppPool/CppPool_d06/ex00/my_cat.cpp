//
// my_cat.cpp for my_cat in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d06/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 11 09:21:07 2016 Gwendoline Rodriguez
// Last update Mon Jan 11 12:57:08 2016 Gwendoline Rodriguez
//

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ios>

void	my_cat(char **av)
{
  int	i;

  i = 0;
  char c;
  while (av[++i] != NULL)
    {
      std::ifstream file(av[i], std::ios::in);
      if (!file)
	std::cerr << "my_cat: " << av[i] <<": No such file or directory"<< std::endl;
      else
	while (file.get(c))
	  std::cout << c;
    }
}

int	main(int ac, char **av)
{
  if (ac >= 2)
    my_cat(av);
  else
    std::cout << "my_cat: Usage : ./my_cat file [...]\n";
  return (0);
}
