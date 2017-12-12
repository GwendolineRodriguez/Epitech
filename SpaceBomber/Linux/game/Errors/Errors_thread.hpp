//
// Errors.hpp for  in /home/denesys/rendu/Semestre_4/C++
// 
// Made by Simon Julie
// Login   <denesys@epitech.net>
// 
// Started on  Wed Apr 13 10:26:16 2016 Simon Julie
// Last update Wed May 18 10:25:55 2016 Simon Julie
//

#ifndef _ERRORS_HPP_
# define _ERRORS_HPP_

#include <string>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Errors.hh"

class ThreadError : public AllError
{
public :
  ThreadError(std::string const &message);
  ~ThreadError() throw(){};
};

#endif
