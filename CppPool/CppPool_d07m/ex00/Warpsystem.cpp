//
// Warpsystem.cpp for warsystem in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 11:00:17 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 13:39:30 2016 Gwendoline Rodriguez
//

#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor() {
}

WarpSystem::QuantumReactor::~QuantumReactor() {
}

WarpSystem::Core::Core(QuantumReactor *reactor) {
  this->_coreReactor = reactor;
}

WarpSystem::Core::~Core() {
}

bool	WarpSystem::QuantumReactor::isStable()
{
  return (this->_stability);
}

void    WarpSystem::QuantumReactor::setStability(bool stability)
{
  this->_stability = stability;
}

WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor()
{
  return this->_coreReactor;
}
