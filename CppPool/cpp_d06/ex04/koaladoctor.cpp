//
// koaladoctor.cpp for koaladoctor in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d06/ex04
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 11 18:09:52 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 08:34:47 2016 Gwendoline Rodriguez
//

#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
  std::cout << "Dr." << name << ": Je suis le Dr."<< name << " ! Comment Kreoggez-vous ?" << std::endl;
  this->work = false;
}

KoalaDoctor::~KoalaDoctor()
{
  this->name.empty();;
}

void            KoalaDoctor::diagnose(SickKoala *SickKoala)
{
  std::string   drug[] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d'eucalyptus"};
  std::string   report = SickKoala->getName() + ".report";
  std::ofstream	file(report.c_str(), std::ios::out);


  std::cout << "Dr." << this->name << ": Alors qu'est-ce qui vous goerk Mr."
	    << SickKoala->getName() << " \?" << std::endl;

  SickKoala->poke();
  if (file)
    {
      file << drug[random() % 5] << std::endl;
      file.close();
    }
}

void            KoalaDoctor::timeCheck()
{
  if (this->work)
    std::cout << "Dr."<< this->name << ": Je commence le travail !" << std::endl;
  else if (!this->work)
    std::cout << "Dr."<< this->name << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
  this->work = !this->work;
}

// int		main()
// {
//   KoalaNurse    KoalaNurse(194) ;
//   SickKoala     SickKoala("Koko");
//   KoalaDoctor	KoalaDoctor("House");

//   KoalaDoctor.diagnose(&SickKoala);
//   KoalaDoctor.timeCheck();
//   return 0;
// }
