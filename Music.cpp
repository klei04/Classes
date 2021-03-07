//Music class getters and setters.
//Child of Media.

#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music() {
  strcpy(mediaType, "MUSIC");
}

char* Music::getArtist() {
  return artist;
}

char* Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}

void Music::setArtist(char* newArtist) {
  strcpy(artist, newArtist);
}

void Music::setDuration(char* newDuration) {
  strcpy(duration, newDuration);
}

void Music::setPublisher(char* newPublisher) {
  strcpy(publisher, newPublisher);
}
