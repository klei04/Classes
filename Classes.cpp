//This is a program that creates a database of 3 media types.
//The program can add media, search for media, and delete media.
//Author: Kevin Lei
//Date: 3/6/2021

#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Videogame.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

//Function Prototypes
void ADD(vector<Media*>* & database);
void SEARCH(vector<Media*>* database);
void DELETE(vector<Media*>* & database);

//Main Function
int main() {
  char input[7];
  cout << "Welcome to the media database." << endl;

  //Creating the vector pointer of Media pointers. Data is on the heap.
  vector<Media*>* database = new vector<Media*>;

  //If the user types in QUIT, the program will end.
  while (strcmp(input, "QUIT") != 0) {

    //User decides what to do in the database.
    cout << "Please type 'ADD' to add media." << endl
	 << "Please type 'SEARCH' to search media." << endl
	 << "Please type 'DELETE' to delete media." << endl
	 << "Please type 'QUIT' to leave." << endl;
    cin.get(input, 7);
    cin.get();

    if (strcmp(input, "ADD") == 0) {
      ADD(database);
    } else if (strcmp(input, "SEARCH") == 0) {
      SEARCH(database);
    } else if (strcmp(input, "DELETE") == 0) {
      DELETE(database);
      
      //Runs if user inputs invalid response
    } else if (strcmp(input, "QUIT") != 0) {
      cout << "Please type a valid response." << endl;
    }		   
  }
  return 0;
}

//Function to add media
void ADD(vector<Media*>* & database) {
    char addType[11];
  
    cout << "Type 'VIDEOGAME' to add a videgame." << endl
	 << "Type 'MUSIC' to add music." << endl
	 << "Type 'MOVIE' to add a movie." << endl;
    cin.get(addType, 11);
    cin.get();

    char title[50];
    char year[5];
    
    if (strcmp(addType, "VIDEOGAME") == 0) {
      char publisher[50];
      char rating[5];

      //Reading in the fields for a videogame file.
      cout << "Please type the title." << endl;
      cin.get(title, 50);
      cin.get();
      cout << "Please type the year." << endl;
      cin.get(year, 5);
      cin.get();
      cout << "Please type the publisher." << endl;
      cin.get(publisher, 50);
      cin.get();
      cout << "Please type the rating." << endl;
      cin.get(rating, 5);
      cin.get();

      //Making the Videogame and adding it to the vector
      Videogame* newVideogame = new Videogame();
      newVideogame->setTitle(title);
      newVideogame->setYear(year);
      newVideogame->setPublisher(publisher);
      newVideogame->setRating(rating);
      database->push_back(newVideogame);
      
    } else if (strcmp(addType, "MUSIC") == 0) {
      char artist[50];
      char duration[50];
      char publisher[50];

      //Reading in the fields for a music file.
      cout << "Please type the title." << endl;
      cin.get(title, 50);
      cin.get();
      cout << "Please type the year." << endl;
      cin.get(year, 5);
      cin.get();
      cout << "Please type the artist." << endl;
      cin.get(artist, 50);
      cin.get();
      cout << "Please type the duration." << endl;
      cin.get(duration, 50);
      cin.get();
      cout << "Please type the publisher." << endl;
      cin.get(publisher, 50);
      cin.get();

      //Making the Music and adding it to the vector
      Music* newMusic = new Music();
      newMusic->setTitle(title);
      newMusic->setYear(year);
      newMusic->setArtist(artist);
      newMusic->setDuration(duration);
      newMusic->setPublisher(publisher);
      database->push_back(newMusic);
      
    } else if (strcmp(addType, "MOVIE") == 0) {
      char director[50];
      char duration[50];
      char rating[5];
      
      //Reading in the fields for a movie file.
      cout << "Please type the title." << endl;
      cin.get(title, 50);
      cin.get();
      cout << "Please type the year." << endl;
      cin.get(year, 5);
      cin.get();
      cout << "Please type the director." << endl;
      cin.get(director, 50);
      cin.get();
      cout << "Please type the duration." << endl;
      cin.get(duration, 50);
      cin.get();
      cout << "Please type the rating." << endl;
      cin.get(rating, 50);
      cin.get();

      //Making the Movie and adding it to the vector
      Movie* newMovie = new Movie();
      newMovie->setTitle(title);
      newMovie->setYear(year);
      newMovie->setDirector(director);
      newMovie->setDuration(duration);
      newMovie->setRating(rating);
      database->push_back(newMovie);

      //Runs if user inputs invalid response
    } else {
      cout << "Please type a valid response." << endl;
    }
}

//Function to search and print media.
void SEARCH(vector<Media*>* database) {
    char searchType[6];
    char searchTerm[50];
    bool found = false;

    //Asking user how they want to search
    cout << "Type 'TITLE' to search by title." << endl
	 << "Type 'YEAR' to search by year." << endl;
    cin.get(searchType, 6);
    cin.get();

    //Search by title
    if (strcmp(searchType, "TITLE") == 0) {

      //Reading in the title
      cout << "Please type the title." << endl;
      cin.get(searchTerm, 50);
      cin.get();
      cout << endl;

      //Iterates through the vector
      for (vector<Media*>::iterator it = database->begin(); it != database->end(); it++) {

	//Checking it a media file matches the title
	if (strcmp((*it)->getTitle(), searchTerm) == 0) {
	  found = true;

	  //Printing out the fields depending on the media type
	  if (strcmp((*it)->getType(), "VIDEOGAME") == 0) {
	    cout << "Media Type: Videogame" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Publisher: " << (static_cast<Videogame*>(*it))->getPublisher() << endl;
	    cout << "Rating: " << (static_cast<Videogame*>(*it))->getRating() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MUSIC") == 0) {
	    cout << "Media Type: Music" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Artist: " << (static_cast<Music*>(*it))->getArtist() << endl;
	    cout << "Duration: " << (static_cast<Music*>(*it))->getDuration() << endl;
	    cout << "Publisher: " << (static_cast<Music*>(*it))->getPublisher() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MOVIE") == 0) {
	    cout << "Media Type: Movie" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Director: " << (static_cast<Movie*>(*it))->getDirector() << endl;
	    cout << "Duration: " << (static_cast<Movie*>(*it))->getDuration() << endl;
	    cout << "Rating: " << (static_cast<Movie*>(*it))->getRating() << endl << endl;
	  }  
	}
      }

      //Runs if no file was found using the search term
      if (found == false) {
        cout << "No media found." << endl;
      }

      //Search by year
    } else if (strcmp(searchType, "YEAR") == 0) {
      //Reading in the year
      cout << "Please type the year." << endl;
      cin.get(searchTerm, 50);
      cin.get();
      cout << endl;

      //Iterates through the vector
      for (vector<Media*>::iterator it = database->begin(); it != database->end(); it++) {

	//Checking it a media file matches the title
	if (strcmp((*it)->getYear(), searchTerm) == 0) {
	  found = true;

	  //Printing out the fields depending on the media type
	  if (strcmp((*it)->getType(), "VIDEOGAME") == 0) {
	    cout << "Media Type: Videogame" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Publisher: " << (static_cast<Videogame*>(*it))->getPublisher() << endl;
	    cout << "Rating: " << (static_cast<Videogame*>(*it))->getRating() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MUSIC") == 0) {
	    cout << "Media Type: Music" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Artist: " << (static_cast<Music*>(*it))->getArtist() << endl;
	    cout << "Duration: " << (static_cast<Music*>(*it))->getDuration() << endl;
	    cout << "Publisher: " << (static_cast<Music*>(*it))->getPublisher() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MOVIE") == 0) {
	    cout << "Media Type: Movie" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Director: " << (static_cast<Movie*>(*it))->getDirector() << endl;
	    cout << "Duration: " << (static_cast<Movie*>(*it))->getDuration() << endl;
	    cout << "Rating: " << (static_cast<Movie*>(*it))->getRating() << endl << endl;
	  }  
	}
      }

      //Runs if no file was found using the search term
      if (found == false) {
        cout << "No media found." << endl;
      }

      //Runs if user inputs invalid response
    } else {
      cout << "Please type a valid response." << endl;
    }

}

//Function to delete media.
void DELETE(vector<Media*>* & database) {
    char deleteType[6];
    char deleteTerm[50];
    bool found = false;
    int deleteIndex = 0;

    //Asking user how they want to delete
    cout << "Type 'TITLE' to delete by title." << endl
	 << "Type 'YEAR' to delete by year." << endl;
    cin.get(deleteType, 6);
    cin.get();

    //Delete by title
    if (strcmp(deleteType, "TITLE") == 0) {

      //Reading in the title
      cout << "Please type the title." << endl;
      cin.get(deleteTerm, 50);
      cin.get();
      cout << endl;

      //Iterates through the vector
      for (vector<Media*>::iterator it = database->begin(); it != database->end(); it++) {

	//Checking it a media file matches the title
	if (strcmp((*it)->getTitle(), deleteTerm) == 0) {
	  found = true;

	  //Printing out the fields depending on the media type
	  if (strcmp((*it)->getType(), "VIDEOGAME") == 0) {
	    cout << "Media Type: Videogame" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Publisher: " << (static_cast<Videogame*>(*it))->getPublisher() << endl;
	    cout << "Rating: " << (static_cast<Videogame*>(*it))->getRating() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MUSIC") == 0) {
	    cout << "Media Type: Music" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Artist: " << (static_cast<Music*>(*it))->getArtist() << endl;
	    cout << "Duration: " << (static_cast<Music*>(*it))->getDuration() << endl;
	    cout << "Publisher: " << (static_cast<Music*>(*it))->getPublisher() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MOVIE") == 0) {
	    cout << "Media Type: Movie" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Director: " << (static_cast<Movie*>(*it))->getDirector() << endl;
	    cout << "Duration: " << (static_cast<Movie*>(*it))->getDuration() << endl;
	    cout << "Rating: " << (static_cast<Movie*>(*it))->getRating() << endl << endl;
	  }
	  
	  //Confirm if the user would like to delete and then delete the vector space, object, and heap memory. Destructor is called.
	  char confirmDelete[7];
	  cout << "Type DELETE to delete this media. Type something else to not delete this media." << endl;
	  cin.get(confirmDelete, 7);
	  cin.get();
	  if (strcmp(confirmDelete, "DELETE") == 0) {
	    delete (*database)[deleteIndex];
	    database->erase(it);
	    break;
	  }
	}
	deleteIndex++;
      }

      //Runs if no file was found using the delete term
      if (found == false) {
        cout << "No media found." << endl;
      }

      //Delete by year
    } else if (strcmp(deleteType, "YEAR") == 0) {
      //Reading in the year
      cout << "Please type the year." << endl;
      cin.get(deleteTerm, 50);
      cin.get();
      cout << endl;

      //Iterates through the vector
      for (vector<Media*>::iterator it = database->begin(); it != database->end(); it++) {

	//Checking it a media file matches the title
	if (strcmp((*it)->getYear(), deleteTerm) == 0) {
	  found = true;

	  //Printing out the fields depending on the media type
	  if (strcmp((*it)->getType(), "VIDEOGAME") == 0) {
	    cout << "Media Type: Videogame" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Publisher: " << (static_cast<Videogame*>(*it))->getPublisher() << endl;
	    cout << "Rating: " << (static_cast<Videogame*>(*it))->getRating() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MUSIC") == 0) {
	    cout << "Media Type: Music" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Artist: " << (static_cast<Music*>(*it))->getArtist() << endl;
	    cout << "Duration: " << (static_cast<Music*>(*it))->getDuration() << endl;
	    cout << "Publisher: " << (static_cast<Music*>(*it))->getPublisher() << endl << endl;
	  } else if (strcmp((*it)->getType(), "MOVIE") == 0) {
	    cout << "Media Type: Movie" << endl;
	    cout << "Title: " << (*it)->getTitle() << endl;
	    cout << "Year: " << (*it)->getYear() << endl;
	    cout << "Director: " << (static_cast<Movie*>(*it))->getDirector() << endl;
	    cout << "Duration: " << (static_cast<Movie*>(*it))->getDuration() << endl;
	    cout << "Rating: " << (static_cast<Movie*>(*it))->getRating() << endl << endl;
	  }

	  //Confirm if the user would like to delete and then delete the vector space, object, and heap memory. Destructor is called.
	  char confirmDelete[7];
	  cout << "Type DELETE to delete this media. Type something else to not delete this media." << endl;
	  cin.get(confirmDelete, 7);
	  cin.get();
	  if (strcmp(confirmDelete, "DELETE") == 0) {
	    delete (*database)[deleteIndex];
	    database->erase(it);
	    break;
	  }
	}
	deleteIndex++;
      }

      //Runs if no file was found using the delete term
      if (found == false) {
        cout << "No media found." << endl;
      }

      //Runs if user inputs invalid response
    } else {
      cout << "Please type a valid response." << endl;
    }
}
