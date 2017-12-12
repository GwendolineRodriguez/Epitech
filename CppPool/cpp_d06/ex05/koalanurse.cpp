//
// koalanurse.cpp for  koalanurse in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d06/ex03
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 11 16:18:08 2016 Gwendoline Rodriguez
// Last update Mon Jan 11 18:05:58 2016 Gwendoline Rodriguez
//

#include "sickkoala.h"
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int id)
{
  this->id = id;
  this->work = false;
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse "<< this->id << ": Enfin un peu de repos !" << std::endl;
  this->id = 0;
}

void		KoalaNurse::giveDrug(std::string drug, SickKoala *SickKoala)
{
  if (SickKoala)
    SickKoala->takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string report)
{
  std::ifstream	file(report.c_str(), std::ios::in);
  std::string	drug;
  std::string	koala;
  std::size_t	pos;

  koala = report;
  report.clear();
  if (file)
    {
      if (!getline(file, drug))
        return (report);
      if ((pos = koala.find(".report", 0)) != std::string::npos && pos + 7 == koala.length())
        koala.replace(koala.length() - 7, 7, "\0");
      else
	return (report);
      std::cout << "Nurse " << this->id << ": Kreog ! Il faut donner un "
		<< drug << " a Mr." << koala << " !" << std::endl;
      return drug;
    }
  else
    return (report);
  return drug;
}

void            KoalaNurse::timeCheck()
{
  if (this->work)
    std::cout << "Nurse "<< this->id << ": Je commence le travail !" << std::endl;
  else if (!this->work)
    std::cout << "Nurse "<< this->id << ": Je rentre dans ma foret d’eucalyptus !" << std::endl;
  this->work = !this->work;
}

// int             main()
// {
//   KoalaNurse	KoalaNurse(194) ;
//   SickKoala	SickKoala("Koko");


//   KoalaNurse.giveDrug("Mars", &SickKoala);
//   KoalaNurse.readReport("truc");
//   KoalaNurse.timeCheck();
//   return 0;
// }

