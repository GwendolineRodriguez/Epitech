/*
** koaladoctor.h for koaladoctor in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d06/ex04
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 11 18:15:20 2016 Gwendoline Rodriguez
** Last update Mon Jan 11 18:34:22 2016 Gwendoline Rodriguez
*/

#ifndef _KOALADOCTOR_
#define _KOALADOCTOR_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

class           KoalaDoctor{
  std::string   name;
  bool		work;

 public:
  KoalaDoctor(std::string name);
  ~KoalaDoctor();
  void          diagnose(SickKoala *SickKoala);
  void          timeCheck();
};

#endif

