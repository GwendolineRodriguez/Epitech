//
// Borg.hh for Borg.hh in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 13:51:20 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 16:10:13 2016 Gwendoline Rodriguez
//

#ifndef _BORG_HH
#define _BORG_HH

#include "Warpsystem.hh"

namespace	Borg {
  class		Ship {
    int		_side;
    short	_maxWarp;
    WarpSystem::Core *_core;

  public:
    Ship();
    ~Ship();

    void      setupCore(WarpSystem::Core *core);
    void      checkCore();
  };
}

#endif
