//
// Errors.cpp for  in /home/denesys/rendu/Semestre_4/C++/cpp_indie_studio/game/Errors
// 
// Made by Simon Julie
// Login   <denesys@epitech.net>
// 
// Started on  Mon May 16 15:25:59 2016 Simon Julie
// Last update Mon May 16 15:27:12 2016 Simon Julie
//

#include "Errors.hh"

AllError::AllError(std::string const & m): _message(m)
{
}

const char* AllError::what() const throw()
{
  return (this->_message.c_str());
}
