/*
** Event.h for event in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d16/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Thu Jan 21 17:32:06 2016 Gwendoline Rodriguez
** Last update Thu Jan 21 18:24:09 2016 Gwendoline Rodriguez
*/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <cstdlib>

class		Event {
  unsigned int  _time;
  std::string   _name;

 public:
 Event(void) : _time(0), _name("") {}
 Event(unsigned int time, const std::string& name) : _time(time), _name(name) {}
  ~Event(void) {}
 Event(const Event& copy) : _time(copy._time), _name(copy._name) {}
  Event& operator=(const Event& copy) {
    if (this != &copy) {
      _time = copy._time;
      _name = copy._name;
    }
    return *this;
  }
  unsigned int getTime(void) const {return _time;}
  const std::string& getEvent(void) const {return _name;}
  void setTime(unsigned int time) {_time = time;}
  void setEvent(const std::string& name) {_name = name;}
};

#endif
