//Header for Music class.
//Child of Media.

//#ifndef _MUSIC_H_
//#define _MUSIC_H_

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media {
 public:
  Music();
  char* getArtist();
  char* getDuration();
  char* getPublisher();    void setArtist(char* newArtist);
  void setDuration(char* newDuration);
  void setPublisher(char* newPublisher);
 private:
  char artist[50];
  char duration[50];
  char publisher[50];
};

//#endif
