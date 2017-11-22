/*
** DomesticKoala.h for DomesticKoala in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d16/ex01
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Thu Jan 21 12:53:14 2016 Gwendoline Rodriguez
** Last update Thu Jan 21 22:45:02 2016 Gwendoline Rodriguez
*/

#ifndef DOMESTICKOALA_H
#define DOMESTICKOALA_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "KoalaAction.h"

/* class		KoalaAction { */
/*  public: */
/*   KoalaAction(); */
/*   ~KoalaAction(); */

/*   void eat(const std::string &); */
/*   void sleep(const std::string &); */
/*   void goTo(const std::string &); */
/*   void reproduce(const std::string &); */

/* }; */

class		DomesticKoala {
 public:
  explicit DomesticKoala(KoalaAction&);
  explicit DomesticKoala(const DomesticKoala&);
  DomesticKoala& operator=(const DomesticKoala&);
  ~DomesticKoala();

  typedef void (KoalaAction::*methodPointer_t)(const std::string&) ;
  std::vector<methodPointer_t> const* getActions(void) const;

  void	learnAction(unsigned char, methodPointer_t);
  void	unlearnAction(unsigned char);
  void	doAction(unsigned char, const std::string&);
  void	setKoalaAction(KoalaAction&);

 private:
  KoalaAction&                  koalaAction;
  std::vector<methodPointer_t>  action;
  std::vector<char>                     key;
};

#endif
