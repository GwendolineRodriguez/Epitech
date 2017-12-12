//
/*
** toy.h for toy in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 18 09:57:22 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 00:25:28 2016 Gwendoline Rodriguez
*/

#ifndef TOY_H
#define TOY_H

#include <iostream>
#include <fstream>
#include <string>
#include "Picture.h"

class		Buzz;
class		Woody;

class		Toy {
 public:
  enum		ToyType {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  };

  class		Error {
  public:
    Error();
   enum ErrorType {
      UNKNOWN,
      PICTURE,
      SPEAK
   };
    std::string what() const;
    std::string where() const;
    ErrorType type;
  };

 protected:
  ToyType       type;
  std::string	name;
  Picture	picture;
  Error		error;

 public:
  //c_tor/d_tor
  Toy();
  Toy(Toy const&);
  Toy(ToyType type, std::string const& name, std::string const& file);
  Toy& operator=(Toy const&);
  ~Toy();

  //Getters
  ToyType               getType() const;
  std::string const&	getName() const;
  std::string const&	getAscii() const;
  Error&		getLastError();


  //Setters
  void		setName(std::string const&);
  bool		setAscii(std::string const&);

  //Action
  void		speak(std::string const &);
  bool          speak_es(std::string const&);

  Toy& operator<<(std::string const&);

};

std::ostream& operator<<(std::ostream&, Toy const &);

#endif
