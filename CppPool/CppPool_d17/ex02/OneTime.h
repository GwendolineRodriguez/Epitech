/*
** OneTime.h for onetime in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d17/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Fri Jan 22 15:23:26 2016 Gwendoline Rodriguez
** Last update Fri Jan 22 15:24:03 2016 Gwendoline Rodriguez
*/


#ifndef __ONETIME_H__
#define __ONETIME_H__

#include <string>
#include <iostream>

#include "IEncryptionMethod.h"

class OneTime : public IEncryptionMethod {
 protected:
  std::string key;
  int index;

 public:
  OneTime(std::string key);
  virtual ~OneTime();

  virtual void encryptChar(char plainchar);
  virtual void decryptChar(char cipherchar);
  virtual void reset();

};

#endif
