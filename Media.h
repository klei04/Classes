//Header for Media class.
//Parent of Videogame, Music, and Movie.

//#ifndef _MEDIA_H_
//#define _MEDIA_H_

#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  char* getTitle();
  char* getYear();
  void setTitle(char* newTitle);
  void setYear(char* newYear);
  char* getType();
  ~Media();
 protected:
  char mediaType[10];
 private:
  char title[50];
  char year[5];
  //char mediaType[10];
};

//#endif

