/*
** IEncryptionMethod.h for Iencrypt in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d17/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Fri Jan 22 12:36:33 2016 Gwendoline Rodriguez
** Last update Fri Jan 22 12:36:35 2016 Gwendoline Rodriguez
*/

#ifndef _IENCRYPTIONMETHODE_H__
# define _IENCRYPTIONMETHODE_H__

class IEncryptionMethod
{
 public:
  virtual ~IEncryptionMethod() {}
  virtual void encryptChar(char plainchar) = 0;
  virtual void decryptChar(char cipherchar) = 0;
  virtual void reset() = 0;
};

#endif
