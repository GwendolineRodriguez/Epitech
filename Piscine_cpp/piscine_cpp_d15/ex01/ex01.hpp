//
// ex01.hpp for ex01 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d15/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Wed Jan 20 13:00:50 2016 Gwendoline Rodriguez
// Last update Wed Jan 20 13:01:23 2016 Gwendoline Rodriguez
//

#ifndef EX01_HPP
#define EX01_HPP

#include <cstring>

template <typename T>
int compare(T const& A, T const& B) {
  if (A > B)
    return 1;
  else
    return A < B ? -1 : 0;
}

template <>
int compare(char const* const& A, char const* const& B) {
  int res;

  res = std::strcmp(A, B);
  if (res > 0) {
    return 1;
  }
  else
    return res < 0 ? -1 : 0;
}

template <typename T1, typename T2>
int compare(const T1& A, const T2& B) {
  int res;

  res = std::strcmp(A, B);
  if (res > 0)
    return 1;
  else
    return res < 0 ? -1 : 0;
}

#endif


