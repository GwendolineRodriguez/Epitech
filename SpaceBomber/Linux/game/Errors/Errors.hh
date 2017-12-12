//
// Errors.hpp for  in /home/denesys/rendu/Semestre_4/C++/cpp_indie_studio/game/Errors
// 
// Made by Simon Julie
// Login   <denesys@epitech.net>
// 
// Started on  Mon May 16 15:22:43 2016 Simon Julie
// Last update Fri May 27 14:36:39 2016 Simon Julie
//

#ifndef _ERRORS_HH_
# define _ERRORS_HH_

#include <stdexcept>
#include <sstream>
#include <string>

class AllError : public std::exception
{
public :
  AllError(std::string const &message);
  ~AllError() throw(){};
  const char * what() const throw();

private:
  std::string _message;
};

#endif
