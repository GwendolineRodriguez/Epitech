//
// ex04.cpp for ex04 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d15/ex04
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Wed Jan 20 14:39:41 2016 Gwendoline Rodriguez
// Last update Wed Jan 20 14:40:57 2016 Gwendoline Rodriguez
//

#include <string>
#include "ex04.hpp"

template<> Tester<std::string>::Tester() {}
template<> Tester<int>::Tester() {}
template<> Tester<float>::Tester() {}
template<> Tester<double>::Tester() {}

template<> Tester<std::string>::~Tester() {}
template<> Tester<int>::~Tester() {}
template<> Tester<float>::~Tester() {}
template<> Tester<double>::~Tester() {}

template<> bool Tester<int>::equal(const int& A, const int& B) {return A == B;}
template<> bool Tester<float>::equal(const float& A, const float& B) {return A == B;}
template<> bool Tester<double>::equal(const double& A, const double& B) {return A == B;}
template<> bool Tester<std::string>::equal(const std::string& A, const std::string& B) {return A.compare(B) == 0;}

template <> bool equal(int const& A, int const &B) {return A == B;}
template <> bool equal(float const& A, float const &B) {return A == B;}
template <> bool equal(double const& A, double const &B) {return A == B;}
template <> bool equal(std::string const& A, std::string const &B) {return (A.compare(B) == 0);}

