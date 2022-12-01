#include <iostream>
#include <string>

enum {CinemaCity, MaxCinema, CinemaSun};

class Ticket {


	float price = 0;
	int* seatRow = nullptr;
	int noRows = 0;
	char date[50];

	static int TICKET_ID;


public:

	Ticket() {

	};

	Ticket(double price, int* seatRow, int noRows, char date) {

		this->setPrice(price);
		this->setSeats(seatRow,noRows);
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


	void setSeats(int* newSeatRows, int newNoRows) {
		if (newNoRows <= 0) {
			throw "A cinema room cant have 0  seat rows";
		}

		if (this->seatRow != nullptr) {
			delete[] this->seatRow;

			this->seatRow = new int[newNoRows];
			for (int i = 0; i < newNoRows;i++) {
				this->seatRow[1] = newSeatRows[i];
			}
		}

	};

	void setDate(char date) {
		if (date != strftime(date, 50, "DD/MM/YY: %d/%m/%Y")) {
			throw "invalid date format"
		}
		else {
			this->date = date;
		}
	}
	//update
	~Ticket() {
		Ticket::TICKET_ID--;

	};



};
