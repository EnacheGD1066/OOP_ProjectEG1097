#include <iostream>
#include <string>
using namespace std;

enum {CinemaCity, MaxCinema, CinemaSun};

class Ticket {


	float price = 0;
	string date = "";
	string movie = "";
	
	int duration = 0;
	//in minutes 

	static int TICKET_ID;


public:

	Ticket() {

	};

	

	Ticket(double price, string date, string movie, int duration) {

		this->setPrice(price);
		this->setMovie(movie);
		this->setDate(date);
		this->setDuration(duration);
		
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


	void setDuration(int duration) {
		if (duration < 0) {
			throw "Duration can't be negative";
		}
		else {

			this->duration = duration;
		}
	}



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

		};




	}

	float getPrice() {
		return this->price;
	}

	string getMovie() {
		return this->movie;

	}

	string getDate() {
		return this->date;
	}


	int getDuration() {
		return this->duration;
	}
		

	// copy constructor
	Ticket(const Ticket& ticket)
	{
		this->price = ticket.price;
		this->date = ticket.date;
		this->movie = ticket.movie;
		this->duration = ticket.duration;
	}

	~Ticket() {

		Ticket::TICKET_ID--;

	};

	
	// operator << and >> 
	void operator<<(ostream& out) {


		cout << endl << "Price " << this->price;
		cout << endl << " Date : " << this->date;
		cout << endl << " Movie :: " << this->movie;
		cout << endl << "Duration : " << this->duration;

	}


	void operator>>(istream& in) {

		cout << endl <<  " Price: ";
		in >> price;
		cout << endl << "Date : ";
		in >> date;
		cout << endl << " Movie : ";
		in >> movie;
		cout << endl << " Duration :";
		in >> duration;
	}

	// operators 

	void operator*=(float value) {
		this->price *= value;
	}
	
	bool operator<=(float value) {
		return this->price <= value;
	}


	// generic methods

	void convertToHours(int duration) {
		this->duration = duration / 60;
	}

	//tax
	void calculatePriceWithoutTax() {
		float tax = 1.19;

		float priceWithoutTax;
		priceWithoutTax = price - price / 1.19;

	}


};
             

