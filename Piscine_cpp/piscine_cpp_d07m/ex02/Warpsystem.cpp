//
// Warpsystem.cpp for warsystem in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 11:00:17 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 22:45:57 2016 Gwendoline Rodriguez
//

#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true) {}

WarpSystem::QuantumReactor::~QuantumReactor() {}

bool WarpSystem::QuantumReactor::isStable() {
  return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability) {
  this->_stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *reactor) {
  this->_coreReactor = reactor;
}

WarpSystem::Core::~Core() {}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() {
  return (this->_coreReactor);
}
