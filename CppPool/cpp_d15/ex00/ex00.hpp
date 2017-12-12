//
// ex00.hpp for ex00 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d15
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Wed Jan 20 09:45:11 2016 Gwendoline Rodriguez
// Last update Wed Jan 20 12:52:04 2016 Gwendoline Rodriguez
//

#ifndef EX00_HPP
#define EX00_HPP

#include <iostream>

template <typename T>
void swap(T &A, T &B) {
  T tmp;
  tmp = A;
  A = B;
  B = tmp;
}

template <typename T>
T add(T const& A, T const& B) {
  return A + B;
}

template <typename T>
const T& min(T const& A, T const& B) {
  return A < B ? A : B;
}

template <typename T>
const T& max(T const& A, T const& B) {
  return A > B ? A : B;
}

#endif

