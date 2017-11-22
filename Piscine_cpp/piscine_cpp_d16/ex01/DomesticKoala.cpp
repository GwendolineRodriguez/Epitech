//
// DomesticKoala.cpp for DomesticKoala in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d16/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Thu Jan 21 13:08:44 2016 Gwendoline Rodriguez
// Last update Thu Jan 21 17:00:32 2016 Gwendoline Rodriguez
//

#include "DomesticKoala.h"

// KoalaAction::KoalaAction() {}
// KoalaAction::~KoalaAction() {}
// void KoalaAction::eat(const std::string& food) {std::cout << "I eat: " << food << std::endl;}
// void KoalaAction::sleep(const std::string& dream) {
// std::cout << "I sleep, and dream of: " << dream << std::endl;}
// void KoalaAction::goTo(const std::string& place) {std::cout << "I go to: " << place << std::endl;}
// void KoalaAction::reproduce(const std::string& food) {
// std::cout << "I attempt to reproduce with: " << food << std::endl;}

DomesticKoala::DomesticKoala(KoalaAction& copy) : koalaAction(copy){}

DomesticKoala::DomesticKoala(DomesticKoala const& koala) : koalaAction(koala.koalaAction) {
  for (unsigned int i = 0; i < koala.action.size(); ++i)
    action.push_back(koala.action[i]);
  for (unsigned int i = 0; i < koala.key.size(); ++i)
    key.push_back(koala.key[i]);
}

DomesticKoala& DomesticKoala::operator=(const DomesticKoala& koala) {
  if (this != &koala) {
    koalaAction = koala.koalaAction;
    if (!key.empty())
      key.clear();
    if (!action.empty())
      action.clear();
    for (unsigned int i = 0; i < koala.action.size(); ++i)
      action.push_back(koala.action[i]);
    for (unsigned int i = 0; i < koala.key.size(); ++i)
      key.push_back(koala.key.size());
  }
  return *this;
}

DomesticKoala::~DomesticKoala() {}

void		DomesticKoala::learnAction(unsigned char keys, methodPointer_t actions) {
  action.push_back(actions);
  key.push_back(keys);
}

void		DomesticKoala::unlearnAction(unsigned char keys) {
  unsigned int	i;
  while (i < key.size() && key[i] != keys) {++i;}
  key.erase(key.begin() + i);
  action.erase(action.begin() + i);
}

void		DomesticKoala::doAction(unsigned char keys, const std::string& actions) {
  unsigned int i = 0;

  while (i < key.size() && key[i] != keys)
    ++i;
  if (i < key.size())
    (koalaAction.*action[i])(actions);
}
void		DomesticKoala::setKoalaAction(KoalaAction& action) {
  koalaAction = action;
}

// int main()
// {
//   KoalaAction action;
//   DomesticKoala *dk = new DomesticKoala(action);

//   dk->learnAction('<', &KoalaAction::eat);
//   dk->learnAction('>', &KoalaAction::goTo);
//   dk->learnAction('#', &KoalaAction::sleep);
//   dk->learnAction('X', &KoalaAction::reproduce);

//   dk->doAction('>', "{EPITECH.}");
//   dk->doAction('<', "a DoubleCheese");
//   dk->doAction('X', "a Seagull");
//   dk->doAction('#', "The end of the C++ pool, and an Astek burning on Astekstake");
//   return 0;
// }
