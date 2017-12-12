//
// Federation.hh for  in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 09:32:22 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 13:47:08 2016 Gwendoline Rodriguez
//

#ifndef _FEDERATION_HH_
#define _FEDERATION_HH_

#include "Warpsystem.hh"
#include <iostream>
#include <string>

namespace	Federation {
  namespace	Starfleet {
    class	Ship {
      int         _length;
      int         _width;
      std::string _name;
      short       _maxWarp;
      WarpSystem::Core *_core;

    public:
      Ship(int length, int width, std::string name, short maxWarp);
      ~Ship();

      void	setupCore(WarpSystem::Core *core);
      void	checkCore();
    };
  }
  class       Ship {
    int         _length;
    int         _width;
    std::string _name;
    static const short _maxWarp = 1;
    WarpSystem::Core *_core;

  public:
    Ship(int length, int width, std::string name);
    ~Ship();

    void      setupCore(WarpSystem::Core *core);
    void      checkCore();
  };
}

#endif
