#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum {CinemaCity, MaxCinema, CinemaSun};

class Ticket {


	float price = 0;
	string date = "";
	string movie = "";
	static int TICKET_ID;


public:

	Ticket() {

	};

	Ticket(double price, string date, string movie) {

		this->setPrice(price);
		this->setMovie(movie);
		this->setDate(date);
		
	};

	


	//  Ticket::TICKET_ID++;


	void setPrice(float price) {
		if (price < 0) {
			throw "Price can;t be negative";
		}
		else {

			this->price = price;
		}
	};




	void setDate( string date) {
		if (date.size() < 8) {
			throw "Invalid date";
		}
		else {
			this->date = date;
		}
		
		

	};


	void setMovie(string movie) {
		if (movie.size() < 7) {
			throw "This movie name is too short";

		}
		else {
			this->movie = movie;

		}


	}
	//update
	~Ticket() {
		Ticket::TICKET_ID--;

	};

	// getters to be added soon


};
