//
// Warpsystem.hh for warpsystem in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 10:22:50 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 22:46:19 2016 Gwendoline Rodriguez
//

#ifndef WARPSYSTEM_HH_
# define WARPSYSTEM_HH_

namespace WarpSystem {
  class QuantumReactor {
  public:
    QuantumReactor();
    ~QuantumReactor();
    bool isStable();
    void setStability(bool stability);

  private: /* data */
    bool _stability;
  };

  class Core {
  public:
    Core(QuantumReactor *reactor);
    ~Core();
    QuantumReactor *checkReactor();

  private: /* data */
    QuantumReactor *_coreReactor;
  };
}

#endif
