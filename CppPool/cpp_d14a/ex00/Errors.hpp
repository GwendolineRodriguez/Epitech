//
// Errors.hpp for error in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14a/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Tue Jan 19 16:57:18 2016 Gwendoline Rodriguez
// Last update Tue Jan 19 18:25:42 2016 Gwendoline Rodriguez
//

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
public:
  NasaError(std::string const &message,
	    std::string const &component = "Unknown") : _component(component), _message(message) {}
  virtual ~NasaError() throw() {}
  std::string const &getComponent() const {return this->_component;}
  const char* what() const throw() {return _message.c_str();}
protected:
  std::string     _component;
private:
  std::string _message;
};

class MissionCriticalError : public NasaError
{
public:
  MissionCriticalError(std::string const &message,
		       std::string const &component = "Unknown") : NasaError(message, component) {}
  virtual ~MissionCriticalError() throw() {}
};

class LifeCriticalError : public NasaError
{
public:
  LifeCriticalError(std::string const &message,
		    std::string const &component = "Unknown") : NasaError(message, component){}
  virtual ~LifeCriticalError() throw() {}
};

class UserError : public NasaError
{
public:
  UserError(std::string const &message,
	    std::string const &component = "Unknown") : NasaError(message, component) {}
  virtual ~UserError() throw() {}
};

class CommunicationError : public NasaError
{
public:
  CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice") {}
  virtual ~CommunicationError() throw() {}
};

#endif
