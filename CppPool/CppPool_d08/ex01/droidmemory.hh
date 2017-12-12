//
// droidmemory.hh for droidmemory in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d08/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Wed Jan 13 23:56:26 2016 Gwendoline Rodriguez
// Last update Wed Jan 13 23:58:10 2016 Gwendoline Rodriguez
//

#ifndef _DROIDMEMORY_H
#define _DROIDMEMORY_H

#include <string>

class DroidMemory {
private:
  size_t  FingerPrint;
  size_t  Exp;

public:

  DroidMemory();
  DroidMemory(DroidMemory const&);
  DroidMemory& operator=(DroidMemory const &);
  ~DroidMemory();


  size_t  getFingerPrint() const;
  void    setFingerPrint(size_t);
  size_t  getExp() const;
  void    setExp(size_t);


  DroidMemory& operator<<(DroidMemory const&);
  DroidMemory& operator>>(DroidMemory&) const;
  DroidMemory& operator+=(DroidMemory const&);
  DroidMemory& operator+=(size_t const&);
  DroidMemory& operator+(DroidMemory const&) const;
  DroidMemory& operator+(size_t const&) const;

};

std::ostream& operator<<(std::ostream& os, DroidMemory const&);

#endif
