//
// map.hh for  in /home/denesys/rendu/Semestre_4/C++/cpp_indie_studio/games_j
// 
// Made by Simon Julie
// Login   <denesys@epitech.net>
// 
// Started on  Wed May  4 14:32:26 2016 Simon Julie
// Last update Wed May 25 09:05:53 2016 turnu angelo
//

#ifndef _MAP_HH_
# define _MAP_HH_

#include <array>
#include <map>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

# define SIZE_X		(15)
# define SIZE_Y		(8)

enum class e_case
  {
    BOMB = 0,
      FLAM,
      IND_BLOC,
      EMPTY,
      D_BLOC,
      PU,
    PLAYER
  };

enum class e_PU
  {
    BOMB_1 = 0,
    POWER_1,
    SPEED,
    EMPTY
  };

enum class e_command
{
  GO_UP = 0,
    GO_DOWN,
    GO_LEFT,
    GO_RIGHT,
    PUT_BOMB,
    NONE,
    EXIT
};

typedef struct	s_case
{
  e_case  type;
  e_PU    PU_type;
}		t_case;


#endif
