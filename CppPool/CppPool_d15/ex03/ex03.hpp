//
// ex03.hpp for ex03 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d15/ex03
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Wed Jan 20 13:41:31 2016 Gwendoline Rodriguez
// Last update Wed Jan 20 13:53:46 2016 Gwendoline Rodriguez
//

#ifndef EX03_HPP
#define EX03_HPP

template <typename T>
void foreach(T *A, void (&func)(const T& elem), int size) {
    for (int i = 0; i < size; ++i) {
        func(A[i]);
    }
}

template <typename T>
void print(const T &A) {
    std::cout << A << std::endl;
}

#endif
