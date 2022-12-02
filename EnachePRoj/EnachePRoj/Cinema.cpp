#include <iostream>
#include <string>
using namespace std;

// class cinema is actually the location the event takes place
enum CinemaPlace {CinemaCity, MAXCinema, SunCinema};

class Cinema {

	char* adress;
	int seatNumber;
	int* seatRow;
	const static int MAX_CAPACITY=100;


public:
	Cinema() {

	};

	Cinema(char* adress, int seatNumber, int* seatRow){
		this->setAdress(adress);
		this->setSeat(seatNumber, seatRow);
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

	//has some errors... to be updated..
	void setSeat(seat, seatRow) {
		
		if (this->seatNumber != nullptr) {
			delete[] this->seatNumber;
		}
		if (seatNumber > Cinema::MAX_CAPACITY) {
			throw "Invalid seat number";
		}


		// getters to be made...

	
	}




	char* getAdress() {
		
		char* adressCopy = new char[strlen(this->adress) + 1];
		strcpy(adressCopy, this->adress);
		return adressCopy;
	}


};