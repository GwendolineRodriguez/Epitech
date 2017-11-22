//
// Warpsystem.hh for warpsystem in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 10:22:50 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 13:47:22 2016 Gwendoline Rodriguez
//

#ifndef _WARPSYSTEM_HH_
#define _WARPSYSTEM_HH_

#include <iostream>
#include <string>

namespace       WarpSystem {
  class         QuantumReactor {
    bool        _stability;

  public:
    QuantumReactor();
    ~QuantumReactor();
    bool        isStable();
    void        setStability(bool);
  };

  class               Core {
    QuantumReactor    *_coreReactor;

  public:
    Core(QuantumReactor *reactor);
    ~Core();
    QuantumReactor*	checkReactor();
  };
}

#endif
