//Videogame class getters and setters.
//Child of Media.

#include <iostream>
#include <cstring>
#include "Videogame.h"

using namespace std;

Videogame::Videogame() {
  strcpy(mediaType, "VIDEOGAME");
 }

char* Videogame::getPublisher() {
  return publisher;
}

char* Videogame::getRating() {
  return rating;
}

void Videogame::setPublisher(char* newPublisher) {
  strcpy(publisher, newPublisher);
}

void Videogame::setRating(char* newRating) {
  strcpy(rating, newRating);
}
