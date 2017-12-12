/*
** koalanurse.h for koalanurse in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d06/ex03
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 11 16:16:35 2016 Gwendoline Rodriguez
** Last update Mon Jan 11 17:57:41 2016 Gwendoline Rodriguez
*/

#ifndef _KOALANURSE_
#define _KOALANURSE_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

class           KoalaNurse{
  int		id;
  bool		work;

 public:
  KoalaNurse(int id);
  ~KoalaNurse();
  void          giveDrug(std::string drug, SickKoala *SickKoala);
  std::string   readReport(std::string report);
  void		timeCheck();
};

#endif

