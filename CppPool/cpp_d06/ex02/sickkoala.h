/*
** sickkoala.h for sickkoala in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d06/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 11 13:22:57 2016 Gwendoline Rodriguez
** Last update Mon Jan 11 15:33:17 2016 Gwendoline Rodriguez
*/

#ifndef _SICKKOALA_
#define _SICKKOALA_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

class		SickKoala
{
  std::string	name;
  public:
  SickKoala(std::string name);
  ~SickKoala();
  void          poke();
  bool		takeDrug(std::string str);
  void		overDrive(std::string str);
};

#endif
