#include <iostream>
#include <string>


using namespace std;


class Customer {

	string firstName = "";
	string lastName = "";
	char* phoneNo = nullptr;
	int age = 0;

	// to be implemented - the rule of 3...
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


	//copy constructor 
	Customer(const Customer& customer)
	{
		this->firstName = customer.firstName;
		this->lastName = customer.lastName;
		this->phoneNo = customer.phoneNo;
		this->age = customer.age;
	}


	// destructor
	~Customer() {
		delete[] this->phoneNo;
	}

	// operators 

	 // << operator >> and << 
	void operator<<(ostream& out) {

		cout << endl << "First Name " << this->firstName;

		cout << endl << "Last Name: " << this->lastName;
		cout << endl << "Phone number : " << this->phoneNo;
		cout << endl << "Age " << this->age;
		
	}


	void operator>>(istream& in) {

		cout << endl << "First Name: ";
		in >> firstName;
		cout << endl << "Last Name : ";
		in >> lastName;
		cout << endl << " Phone Number : ";
		in >> phoneNo;
		cout << endl << "Age :";
		in >> age;
	}

	char& operator[](int index) {
		if (index < 0 || index >= strlen(this->phoneNo)) {
			throw "Error";
		}
		return this->phoneNo[index];
	}


	friend bool operator==(Customer& c1, Customer& c2) {
		return c1.getFirstName() == c2.getFirstName();
	}

};

