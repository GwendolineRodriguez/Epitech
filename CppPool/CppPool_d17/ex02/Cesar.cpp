//
// Cesar.cpp for cesar in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d17/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Fri Jan 22 14:44:29 2016 Gwendoline Rodriguez
// Last update Fri Jan 22 15:51:44 2016 Gwendoline Rodriguez
//

#include "Cesar.h"

Cesar::Cesar() : _shift(3) {}

Cesar::~Cesar() {}

void Cesar::encryptChar(char character)
{
    if (character >= 'a' && character <= 'z')
        character = 'a' + ((character - 'a' + _shift) % 26);
    else if (character >= 'A' && character <= 'Z')
        character = 'A' + ((character - 'A' + _shift) % 26);
    std::cout << character;
    ++_shift;
}

void Cesar::decryptChar(char character)
{
    if (character >= 'a' && character <= 'z')
    {
        character = (character - 'a' - _shift) % 26;
        if (character < 0)
            character += 26;
        character += 'a';
    }
    else if (character >= 'A' && character <= 'Z')
    {
        character = (character - 'A' - _shift) % 26;
        if (character < 0)
            character += 26;
        character += 'A';
    }
    std::cout << character;
    ++_shift;
}

void Cesar::reset() {
    _shift = 3;
}
