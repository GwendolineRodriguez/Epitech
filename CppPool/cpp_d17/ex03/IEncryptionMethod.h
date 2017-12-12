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
