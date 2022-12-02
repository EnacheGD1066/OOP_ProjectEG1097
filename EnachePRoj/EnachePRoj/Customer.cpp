#include <iostream>
#include <string>

using namespace std;


class Customer {

	string firstName = "";
	string lastName = "";
	char* phoneNo = nullptr;
	int age = 0;


public:

	Customer() {

	}

	Customer(string firstName, string lastName, char* phoneNo, int age) {

		this->setFirstName(firstName);
		this->setLastName(lastName);
		this->setPhoneNo(phoneNo);
		this->setAge(age);
	}

	void setFirstName(string firstName) {
		if (firstName.size() > 3) {
			throw "Name can;t be smaller than 3 letters";

		}
		else {
			this->firstName = firstName;
		}
	}


	void setLastName(string lastName) {
		if (lastName.size() > 3) {
			throw "Last name too short";

		}
		else {
			this->lastName = lastName;
		}
	}



	void setPhoneNo(char* phoneNo) {
		if (this->phoneNo != nullptr) {
			delete[] this->phoneNo;
		};
		if (strlen(phoneNo) != 10) {
			throw "Phone number must have 10 digits";
		}
		else {
			this->phoneNo = new char[strlen(phoneNo) + 1];
			for (int i = 0; i < strlen(phoneNo) + 1;i++) {
				this->phoneNo[i] = phoneNo[i];
			}
		}


	};


	void setAge(int age) {
		if (age < 16) {
			throw "You cant buy a ticket";
		}
		else {
			this->age = age;
		}

	}

	string getFirstName() {
		return this->firstName;
	}

	string getLastName() {
		return this->lastName;

	}

	int getAge() {
		return this->age;

	}

	string getPhoneNo() {
		return this->phoneNo;
	}




};
