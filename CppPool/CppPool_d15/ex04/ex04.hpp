//
// ex04.hpp for ex04 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d15/ex04
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Wed Jan 20 14:05:00 2016 Gwendoline Rodriguez
// Last update Wed Jan 20 14:05:20 2016 Gwendoline Rodriguez
//

#ifndef EX04_HH
#define EX04_HH

template <typename T>
bool equal(T const& A, T const& B);

template <typename T>
class Tester {
public:
    Tester();
    ~Tester();
    bool equal(T const&, T const&);
};

#endif
