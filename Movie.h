//Header for Movie class.
//Child of Media.

//#ifndef _MOVIE_H_
//#define _MOVIE_H_

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie();
  char* getDirector();
  char* getDuration();
  char* getRating();
  void setDirector(char* newDirector);
  void setDuration(char* newDuration);
  void setRating(char* newRating);
 private:
  char director[50];
  char duration[50];
  char rating[5];
};

//#endif
