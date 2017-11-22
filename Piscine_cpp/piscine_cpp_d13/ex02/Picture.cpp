//
// Picture.cpp for Picture in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 18 09:14:58 2016 Gwendoline Rodriguez
// Last update Mon Jan 18 13:51:13 2016 Gwendoline Rodriguez
//

#include "Picture.h"

Picture::Picture() {
  this->data = "";
}

Picture::Picture(Picture const &picture) : data(picture.data) {
}

Picture& Picture::operator=(Picture const &picture) {
  if (&picture != this)
    this->data = picture.data;
  return *this;
}

Picture::Picture(const std::string& file) {
  std::ifstream		stream(file.c_str());
  std::string tmp;
  if (stream) {
    this->data = "";
    while (getline(stream, tmp, '\0'))
      this->data += tmp;
    stream.close();
  }
  else
    this->data = "ERROR";
}

Picture::~Picture() {
}

bool		Picture::getPictureFromFile(const std::string& file) {
  std::ifstream         stream(file.c_str());
  std::string tmp;
  if (stream) {
    this->data = "";
    while (getline(stream, tmp, '\0'))
      this->data += tmp;
    stream.close();
  }
  else
    return false;
  return true;
}
