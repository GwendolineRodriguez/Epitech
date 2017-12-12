/*
** Picture.h for Picture in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 18 09:10:09 2016 Gwendoline Rodriguez
** Last update Mon Jan 18 13:33:12 2016 Gwendoline Rodriguez
*/

#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <fstream>
#include <string>

class		Picture {
 public:
  std::string   data;

  //c_tor/d_tor
  Picture();
  Picture(Picture const &);
  Picture(const std::string& file);
  Picture& operator=(Picture const &);
  ~Picture();

  //Actions
  bool		getPictureFromFile(const std::string& file);

};

#endif
