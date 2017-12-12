//
// droidmemory.cpp for droidmemory in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d08/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Wed Jan 13 23:55:39 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 00:01:50 2016 Gwendoline Rodriguez
//

#include <stdlib.h>
#include <iostream>
#include "droidmemory.hh"

DroidMemory::DroidMemory() : FingerPrint(random()), Exp(0) {}

DroidMemory::DroidMemory(DroidMemory const &droid) : FingerPrint(droid.FingerPrint), Exp(droid.Exp) {}

DroidMemory&  DroidMemory::operator=(DroidMemory const &droid) {
  if (&droid != this)
    {
      this->FingerPrint = droid.FingerPrint;
      this->Exp = droid.Exp;
    }
  return (*this);
}

DroidMemory::~DroidMemory() {}

DroidMemory& DroidMemory::operator<<(DroidMemory const& droidmemory){
  this->Exp += droidmemory.getExp();
  this->FingerPrint ^= droidmemory.getFingerPrint();
  return (*this);
}

DroidMemory& DroidMemory::operator>>(DroidMemory& droidmemory) const{
  droidmemory.setExp(this->Exp + droidmemory.getExp());
  droidmemory.setFingerPrint(droidmemory.getFingerPrint() ^ this->FingerPrint);
  return (droidmemory);
}

DroidMemory& DroidMemory::operator+=(DroidMemory const& droidmemory) {
  this->Exp += droidmemory.getExp();
  this->FingerPrint ^= droidmemory.getFingerPrint();
  return *this;
}

DroidMemory& DroidMemory::operator+=(size_t const& exp) {
  this->Exp += exp;
  this->FingerPrint ^= exp;
  return *this;
}

DroidMemory& DroidMemory::operator+(DroidMemory const& droidmemory) const{
  DroidMemory *tmp = new DroidMemory();
  tmp->Exp = this->Exp + droidmemory.getExp();
  tmp->FingerPrint = this->FingerPrint ^ droidmemory.getFingerPrint();
  return (*tmp);
}

DroidMemory& DroidMemory::operator+(size_t const& exp) const{
  DroidMemory *tmp = new DroidMemory();
  tmp->Exp = this->Exp + exp;
  tmp->FingerPrint = this->FingerPrint ^ exp;
  return (*tmp);
}

size_t  DroidMemory::getExp() const {
  return (this->Exp);
}

void    DroidMemory::setExp(size_t exp) {
  this->Exp = exp;
}

size_t  DroidMemory::getFingerPrint() const {
  return (this->FingerPrint);
}

void    DroidMemory::setFingerPrint(size_t fingerPrint) {
  this->FingerPrint = fingerPrint;
}

std::ostream& operator<<(std::ostream& os, DroidMemory const& droid) {
  os << "DroidMemory '" << droid.getFingerPrint() << "', " << droid.getExp();

  return (os);
}
