//
// Borg.hh for Borg.hh in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 13:51:20 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 22:43:26 2016 Gwendoline Rodriguez
//

#ifndef BORG_HH_
# define BORG_HH_

#include "Warpsystem.hh"
#include "Destination.hh"

namespace Borg {
  class Ship {
  private:
    int _side;
    short _maxWarp;
    WarpSystem::Core *_core;
    Destination _location;
    Destination _home;

  public:
    Ship();
    ~Ship();

    void setupCore(WarpSystem::Core *core);
    void checkCore();
    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();
  };
}

#endif
