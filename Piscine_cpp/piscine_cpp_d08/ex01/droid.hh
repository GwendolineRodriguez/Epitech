//
// droid.hh for droid in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d08/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Wed Jan 13 23:54:06 2016 Gwendoline Rodriguez
// Last update Wed Jan 13 23:55:03 2016 Gwendoline Rodriguez
//

#ifndef __DROID_HH
#define __DROID_HH

#include <string>
#include "droidmemory.hh"

class Droid {
private:
  std::string Id;
  size_t Energy;
  size_t const Attack;
  size_t const Toughness;
  std::string *Status;
  DroidMemory *BattleData;

public:
  explicit Droid(Droid const &);
  explicit Droid(std::string);
  Droid& operator=(Droid const &);
  ~Droid();

  std::string getId() const;
  void        setId(std::string);
  size_t      getEnergy() const;
  void        setEnergy(size_t);
  std::string *getStatus() const;
  void        setStatus(std::string *);
  size_t      getAttack() const;
  size_t      getToughness() const;
  DroidMemory *getBattleData() const;
  void        setBattleData(DroidMemory *droidMemory);
  bool operator==(Droid const &) const;
  bool operator!=(Droid const &) const;
  void operator<<(size_t &);
};

std::ostream& operator <<(std::ostream&, Droid const &);

#endif
