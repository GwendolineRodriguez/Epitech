//
// ex02.hpp for ex02 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d15/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Wed Jan 20 13:08:28 2016 Gwendoline Rodriguez
// Last update Wed Jan 20 13:29:18 2016 Gwendoline Rodriguez
//

#ifndef EX02_HPP
#define EX02_HPP

#include <iostream>
#include <cstring>

template    <typename T>
T min(T const& A, T const& B) {
  std::cout << "template min" << std::endl;
  return A <= B ? A : B;
}

int min(int const& A, int const& B) {
  std::cout << "non-template min" << std::endl;
  return A <= B ? A : B;
}

template <typename T>
T templateMin(T *A, int const size) {
  T mini = A[0];
  int i = 0;
  while (++i < size)
    mini = min<T>(A[i], mini);
  return mini;
}

int nonTemplateMin(int * A, int const size) {
  int mini = A[0];
  int i = 0;
  while (++i < size)
    mini = min(A[i], mini);
  return mini;
}

#endif

