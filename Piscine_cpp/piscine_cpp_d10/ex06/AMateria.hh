//
// AMateria.hh for AMetaria in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex06
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 16:29:55 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 16:56:33 2016 Gwendoline Rodriguez
//

#ifndef AMATERIA_HH
#define AMATERIA_HH

class AMateria
{
private:
  unsigned int xp_;
  std::string const type;

public:
  AMateria();
  AMetaria(AMetaria const &);
  AMateria(std::string const & type);
  AMateria& operator=(AMateria const &);
  virtual ~AMateria();

  std::string const & getType() const; //Returns the materia type
  unsigned int getXP() const; //Returns the Materia’s xp14
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

};

#endif
