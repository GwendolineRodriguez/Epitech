//
// my_convert_temp.cpp for my_convert_temp in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d06/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 11 11:14:40 2016 Gwendoline Rodriguez
// Last update Mon Jan 11 16:08:52 2016 Gwendoline Rodriguez
//

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

void		convert_Celcius(float temp)
{
  float		res;

  res = 9.0 / 5.0 * temp + 32;
  std::cout.precision(3);
  std::cout << std::setw(16) << std::fixed << res << std::setw(16) << "Fahrenheit" << std::endl;
}

void            convert_Fahrenheit(float temp)
{
  float		res;

  res = 5.0 / 9.0 * (temp - 32);
  std::cout.precision(3);
  std::cout << std::setw(16) << std::fixed << res << std::setw(16) << "Celsius" << std::endl;
}

int		main()
{
  char		data[1000];
  float		temp;

  temp = 0;
  std::cin >> temp >> data;

  if (strncmp(data, "Celsius", 7) == 0)
    convert_Celcius(temp);
  if (strncmp(data, "Fahrenheit", 10) == 0)
    convert_Fahrenheit(temp);
  return 0;
}
