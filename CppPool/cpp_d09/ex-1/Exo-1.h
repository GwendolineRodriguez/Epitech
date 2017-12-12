//
// Exo-1.hh for ex-1 in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex-1
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 08:03:36 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 08:03:52 2016 Gwendoline Rodriguez
//



#ifndef __ex_1__Exo_1__
#define __ex_1__Exo_1__

typedef struct  s_cthulhu {
  int         m_power;
  char        *name;
}               t_cthulhu;

t_cthulhu*      NewCthulhu();
void            PrintPower(t_cthulhu* this);
void            Attack(t_cthulhu* this);
void            Sleeping(t_cthulhu* this);

typedef struct  s_koala {
  t_cthulhu   m_parent;
  char        m_isALegend;
}               t_koala;

t_koala*        NewKoala(char* name, char _isALegend);
void            Eat(t_koala* this);

t_cthulhu*      NewCthulhu();
t_koala*        NewKoala(char *name, char _isALegend);


#endif

