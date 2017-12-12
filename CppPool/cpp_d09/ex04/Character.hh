//
// Character.hh for Character in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 09:52:20 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 11:46:54 2016 Gwendoline Rodriguez
//

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <string>

class		Character
{
protected:

  //Essentials
  const std::string	name;
  int		lvl;
  int		Pv;
  int		Energy;

  //characteristics
  int		Strength;
  int		Stamina;
  int		Intelligence;
  int		Spirit;
  int		Agility;

public:
  //c_tor / d_tor
  explicit Character(const std::string&, int);
  ~Character();


  //getters
  const std::string &getName() const;
  int getLvl() const;
  int getPv() const;
  int getPower() const;

  //Actions
  int CloseAttack();
  int RangeAttack();
  void Heal();
  void RestorePower();
  void TakeDamage(int _damage);

  typedef enum AttackRange {
    CLOSE,
    RANGE    } AttackRange;

  AttackRange         Range;
};

#endif

