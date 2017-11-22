//
// Parser.cpp for parser in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d16
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Thu Jan 21 12:41:35 2016 Gwendoline Rodriguez
// Last update Thu Jan 21 15:07:09 2016 Gwendoline Rodriguez
//

#include <iostream>
#include <sstream>
#include "Parser.h"

Parser::Parser() {}
Parser::~Parser() {}

static int add(int a, int b) {return a + b;}
static int sub(int a, int b) {return a - b;}
static int mult(int a, int b) {return a * b;}
static int div(int a, int b) {return a / b;}
static int mod(int a, int b) {return a % b;}

static int doop(int a, int b, char op) {
    switch (op) {
        case '+':
            return add(a, b);
            break;
        case '-':
            return sub(a, b);
            break;
        case '/':
            return div(a, b);
            break;
        case '*':
            return mult(a, b);
            break;
        default:
            return mod(a, b);
            break;
        }
}

void Parser::feed(std::string const& str) {
    int i;
    int nb1;
    int nb2;
    char op;

    i = 0;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            int tmp = 0;
            while (str[i] && str[i] >= '0' && str[i] <= '9') {
                tmp = tmp * 10 + str[i] - '0';
                ++i;
            }
            _operands.push(tmp);
        }
        else if (str[i] == ')') {
            nb2 = _operands.top();
            _operands.pop();
            nb1 = _operands.top();
            _operands.pop();
            op = _operators.top();
            _operators.pop();
            _operands.push(doop(nb1, nb2, op));
            ++i;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%'){
            _operators.push(str[i]);
            ++i;
        }
        else
            ++i;
    }
    nb1 = _operands.top();
    _operands.pop();
    if (!_operands.empty()) {
        if (!_operators.empty()) {
            op = _operators.top();
            _operators.pop();
            nb1 = doop(nb1, _operands.top(), op);
        }
        else {
            nb1 += _operands.top();
            _operands.pop();
        }
    }
    _operands.push(nb1);
}

int Parser::result() const {
    return _operands.top();
}
void Parser::reset() {
    while (!_operands.empty())
        _operands.pop();
    while (!_operators.empty())
        _operators.pop();
}

// int main()
// {
//   Parser p;

//   p.feed("((12*2)+14)");
//   std::cout << p.result() << std::endl;
//   p.feed("((17 % 9) / 4)");
//   std::cout << p.result() << std::endl;
//   p.reset();
//   p.feed("(17 - 4) * 13");
//   std::cout << p.result() << std::endl;
//   return 0;
// }
