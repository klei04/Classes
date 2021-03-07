//Media class getters and setters.
//Parent of Videogame, Music, and Movie.

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

char* Media::getTitle() {
  return title;
}

char* Media::getYear() {
  return year;
}

char* Media::getType() {
  return mediaType;
}

void Media::setTitle(char* newTitle) {
  strcpy(title, newTitle);
}

void Media::setYear(char* newYear) {
  strcpy(year, newYear);
}

Media::~Media() {
  cout << "Media deleted." << endl;
}
