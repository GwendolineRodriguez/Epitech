//
// Federation.hh for  in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 09:32:22 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 22:45:34 2016 Gwendoline Rodriguez
//

#ifndef FEDERATION_HH_
# define FEDERATION_HH_

#include <iostream>
# include <string>
# include "Warpsystem.hh"
# include "Destination.hh"

namespace Federation {
  namespace Starfleet {
    class Ship {
    public:
      Ship (int length, int width, std::string name, short maxWarp);
      ~Ship ();
      void setupCore(WarpSystem::Core *core);
      void checkCore();
      void promote(class Captain *captain);
      bool move(int warp, Destination d);
      bool move(int warp);
      bool move(Destination d);
      bool move();

    private: /* data */
      WarpSystem::Core *_core;
      int _length;
      int _width;
      std::string _name;
      short _maxWarp;
      Captain *_captain;
      Destination _location;
      Destination _home;
    };
    class Captain {
    public:
      Captain(std::string name);
      ~Captain();
      int getAge();
      void setAge(int age);

      std::string _name;

    private:
      int _age;
    };

    class Ensign {
    public:
      explicit Ensign(std::string name);
      ~Ensign();

    private:
      std::string _name;
    };
  }
  class Ship {
  public:
    Ship (int length, int width, std::string name);
    ~Ship();
    void setupCore(WarpSystem::Core *core);
    void checkCore();

    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();

  private:
    WarpSystem::Core *_core;
    int _length;
    int _width;
    std::string _name;
    static const short _maxWarp = 1;
    Destination _location;
    Destination _home;
  };

}

#endif 
