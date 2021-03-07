//Movie class getters and setters.
//Child of Media.

#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie() {
  strcpy(mediaType, "MOVIE");
}

char* Movie::getDirector() {
  return director;
}

char* Movie::getDuration() {
  return duration;
}

char* Movie::getRating() {
  return rating;
}

void Movie::setDirector(char* newDirector) {
  strcpy(director, newDirector);
}

void Movie::setDuration(char* newDuration) {
  strcpy(duration, newDuration);
}

void Movie::setRating(char* newRating) {
  strcpy(rating, newRating);
}
