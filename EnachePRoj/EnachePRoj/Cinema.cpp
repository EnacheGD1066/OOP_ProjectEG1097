#include <iostream>
#include <string>

using namespace std;

// class cinema is actually the location the event takes place
enum CinemaPlace {CinemaCity, MAXCinema, SunCinema};

class Cinema {

	char* adress = nullptr;
	int* seats = nullptr;
	int noRows = 0;
	const static int MAX_CAPACITY=100;


public:
	Cinema() {

	};

	
	Cinema(char* adress, int* seats, int noRows) {
		this->setAdress(adress);
		this->setSeats(seats, noRows);
		
	}



	void setAdress(char* adress) {
		if (strlen(adress) <10) {
			throw "Invalid adress";
		}
		if (this->adress != nullptr)
			delete[] this->adress;
		this->adress = new char[strlen(adress) + 1];
		for (int i = 0; i < strlen(adress) + 1; i++) {
			this->adress[i] = adress[i];
		}

	}

	void setSeats(int* seats, int noRows) {
		if (seats != nullptr) {
			delete[] this->seats;
		}

		// allocating memory
		this->seats = new int[noRows];
		for (int i = 0;i < noRows;i++) {
			this->seats[i] = seats[i];

		}
		this->noRows = noRows;

		//validation 

		if (noRows > Cinema::MAX_CAPACITY) {
			throw "max capacity cannot be exceeded";
		}

	}
	




	char* getAdress() {
		
		char* adress = new char[strlen(this->adress) + 1];
	
		for (int i = 0; i < strlen(this->adress);i++) {
			this->adress[i] = adress[i];
		}
		return adress;

	}


};