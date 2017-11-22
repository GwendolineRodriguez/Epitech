//
// OneTime.cpp for OneTime in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d17/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Fri Jan 22 15:22:56 2016 Gwendoline Rodriguez
// Last update Fri Jan 22 15:23:10 2016 Gwendoline Rodriguez
//

#include "OneTime.h"

OneTime::OneTime(std::string key) {
  this->key = key;
  index = 0;
}

OneTime::~OneTime() {

}

void OneTime::encryptChar(char plainchar) {
  if (isalpha(plainchar)) {
    int base = plainchar > 96 ? 97 : 65;
    int kbase = key[index] > 96 ? 97 : 65;
    plainchar = (plainchar - base + (key[index] - kbase)) % 26 + base;
  }
  std::cout << plainchar;
  index = (index + 1) % key.size();
}

void OneTime::decryptChar(char cipherchar) {
  if (isalpha(cipherchar)) {
    int base = cipherchar > 96 ? 122 : 90;
    int kbase = key[index] > 96 ? 97 : 65;
    cipherchar = (cipherchar - base - (key[index] - kbase)) % 26 + base;
  }
  std::cout << cipherchar;
  index = (index + 1) % key.size();
}

void OneTime::reset() {
  index = 0;
}

