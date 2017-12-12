//
// game_errors.hpp for  in /home/denesys/rendu/Semestre_4/C++/cpp_indie_studio/game/Errors
// 
// Made by Simon Julie
// Login   <denesys@epitech.net>
// 
// Started on  Mon May 16 15:21:51 2016 Simon Julie
// Last update Fri May 27 14:39:31 2016 Simon Julie
//

#ifndef _FILE_ERRORS_HH_
# define _FILE_ERRORS_HH_

#include "Errors.hh"

class FileErrors : public AllError
{
public :
  FileErrors(std::string const &message);
  ~FileErrors() throw(){};
};

#endif
