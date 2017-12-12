/*
** Parser.h for parser in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d16
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Thu Jan 21 10:02:57 2016 Gwendoline Rodriguez
** Last update Thu Jan 21 12:43:19 2016 Gwendoline Rodriguez
*/

#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <string>

class Parser {
  std::stack<char>    _operators;
  std::stack<int>     _operands;

 public:
  Parser();
  ~Parser();

  void feed(std::string const&);
  int result() const;
  void reset();
};

#endif
