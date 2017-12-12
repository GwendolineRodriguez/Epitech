//
// game_errors.hpp for  in /home/denesys/rendu/Semestre_4/C++/cpp_indie_studio/game/Errors
// 
// Made by Simon Julie
// Login   <denesys@epitech.net>
// 
// Started on  Mon May 16 15:21:51 2016 Simon Julie
// Last update Mon May 16 15:35:09 2016 Simon Julie
//

#ifndef _GAME_ERRORS_HH_
# define _GAME_ERRORS_HH_

#include "Errors.hh"

class GameErrors : public AllError
{
public :
  GameErrors(std::string const &message);
  ~GameErrors() throw(){};
};

#endif
