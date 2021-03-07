//Header for Videogame class.
//Child of Media.

//#ifndef _VIDEOGAME_H_
//#define _VIDEOGAME_H_

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Videogame : public Media {
 public:
  Videogame();
  char* getPublisher();
  char* getRating();
  void setPublisher(char* newPublisher);
  void setRating(char* newRating);
 private:
  char publisher[50];
  char rating[5];
};

//#endif
