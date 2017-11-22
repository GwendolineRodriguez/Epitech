//
// droid.cpp for droid in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d08/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Wed Jan 13 23:53:22 2016 Gwendoline Rodriguez
// Last update Wed Jan 13 23:59:11 2016 Gwendoline Rodriguez
//

#include <iostream>
#include "droid.hh"

Droid::Droid(std::string Id) : Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by")) {
  this->Id = Id;
  this->BattleData = new DroidMemory();
  std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : Id(droid.getId()), Energy(droid.getEnergy()), Attack(25), Toughness(15), Status(new std::string(*droid.getStatus())) {
  this->BattleData = new DroidMemory(*droid.getBattleData());
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid&  Droid::operator=(Droid const &droid) {
  if (&droid != this)
    {
      this->Id = droid.getId();
      this->Energy = droid.getEnergy();
      if (this->Status)
	delete this->Status;
      this->Status = new std::string(*droid.getStatus());
      if (this->BattleData)
	delete this->BattleData;
      this->BattleData = new DroidMemory(*droid.getBattleData());
    }
  return *this;
}

Droid::~Droid() {
  delete this->Status;
  delete this->BattleData;
  std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

size_t  Droid::getEnergy() const{
  return (this->Energy);
}

void    Droid::setEnergy(size_t Energy) {
  this->Energy = Energy;
}

std::string Droid::getId() const {
  return (this->Id);
}

void    Droid::setId(std::string Id) {
  this->Id = Id;
}

std::string *Droid::getStatus() const {
  return (this->Status);
}

void Droid::setStatus(std::string *status) {
  this->Status = status;
}

size_t Droid::getAttack() const{
  return (this->Attack);
}

size_t Droid::getToughness() const {
  return (this->Toughness);
}

DroidMemory *Droid::getBattleData() const {
  return (this->BattleData);
}

void        Droid::setBattleData(DroidMemory *droidMemory) {
  this->BattleData = droidMemory;
}

bool    Droid::operator==(Droid const &droid) const {
  return (this->Status->compare(*droid.getStatus()) == 0);
}

bool    Droid::operator!=(Droid const &droid) const {
  return (this->Status->compare(*droid.getStatus()) != 0);
}

void    Droid::operator<<(size_t &reload) {
  size_t value;

  value = this->Energy + reload <= 100 ? reload : 100 - this->Energy;
  this->Energy += value;
  reload -= value;
}

std::ostream& operator <<(std::ostream& os, Droid const& droid) {
  os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();

  return os;
}

int main()
{
  DroidMemory dm;
  DroidMemory dn;
  DroidMemory dg;
  dm += 42;
  DroidMemory dn1 = dm;
  std::cout << dm << std::endl;
  dn << dm;
  dn >> dm;
  dn << dm;
  std::cout << dn << std::endl;
  std::cout << dm << std::endl;
  dg = dm + dn1;
}
