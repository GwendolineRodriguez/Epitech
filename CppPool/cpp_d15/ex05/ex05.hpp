//
// ex05.hpp for ex05 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d15/ex05
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Wed Jan 20 15:25:39 2016 Gwendoline Rodriguez
// Last update Wed Jan 20 15:49:09 2016 Gwendoline Rodriguez
//

#ifndef EX05_HPP
#define EX05_HPP

#include <exception>
#include <iostream>

template <typename T>
class array {
public:
    array() : _array(0), _size(0) {}
    array(unsigned int n) : _array(new T[n]), _size(n) {}
    array(array const& copy) : _array(new T[copy._size]), _size(copy._size) {
        for (unsigned int i = 0; i < copy._size; ++i) {
            _array[i] = copy._array[i];
        }
    }
    array& operator=(array const& copy) {
        if (this != &copy) {
            if (_array)
                delete []_array;
            _array = new T[copy._size];
            for (unsigned int i = 0; i < copy._size; ++i) {
                _array[i] = copy._array[i];
            }
            _size = copy._size;
        }
        return *this;
    }

    void dump() const {
        std::cout << "[";
        for (unsigned int i = 0; i < _size; ++i) {
            std::cout << _array[i];
            if (i + 1 < _size)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    T& operator[](const unsigned int& i){
        T* tmp;

        try {
            if (i >= _size) {
                tmp = new T[i + 1];
                for (unsigned int j = 0; j < _size; ++j) {
                    tmp[j] = _array[j];
                }
                delete [] _array;
                _array = tmp;
		delete [] tmp;
                _size = i + 1;
            }
            return _array[i];
        }
        catch(...) {
            throw std::exception();
        }
    }
    T& operator[](const unsigned int& i) const{
        if (i >= _size)
            throw std::exception();
        return _array[i];
    }

    template<typename U>
    array<U> const& convertTo(U (*conv)(T const& var)) {
        array<U> *arr = new array<U>(_size);
        for (unsigned int i = 0; i < _size; ++i) {
            (*arr)[i] = conv(_array[i]);
        }
        return *arr;
    }

    unsigned int size() const {return _size;}

    ~array() {if (_array) delete [] _array;}
private:
    T* _array;
    unsigned int _size;
};

template<> void array<bool>::dump() const {
    std::cout << "[";
    for (unsigned int i = 0; i < _size; ++i) {
        if (_array[i] == false) {
            std::cout << "false";
        }
        else
            std::cout << "true";
        if (i + 1 < _size)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

#endif
