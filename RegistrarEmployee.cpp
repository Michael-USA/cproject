#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "RegistrarEmployee.h"

using namespace std;

RegistrarEmployee::RegistrarEmployee() = default;

RegistrarEmployee::~RegistrarEmployee() = default;

string RegistrarEmployee::sendFName() { //Displays to user that data for fName was sent.
	std::cout << "User First Name " << fName << " Sent" << std::endl;
	return(fName);
}

string RegistrarEmployee::sendLName() { //Displays to user that data for lName was sent.
	std::cout << "User Last Name " << lName << " Sent" << std::endl;
	return(lName);
}

string RegistrarEmployee::sendEmail() { //Displays to user that data for email was sent.
	std::cout << "User Email " << email << " Sent" << std::endl;
	return(email);
}

string RegistrarEmployee::sendSSN() { //Displays to user that data for ssn was sent.
	std::cout << "User Social Security Number " << ssn << " Sent" << std::endl;
	return(ssn);
}

string RegistrarEmployee::sendAddress() { //Displays to user that data for address was sent.
	std::cout << "User Address " << address << " Sent" << std::endl;
	return(address);
}

string RegistrarEmployee::sendCity() { //Displays to user that data for city was sent.
	std::cout << "User City " << city << " Sent" << std::endl;
	return(city);
}

string RegistrarEmployee::sendState() { //Displays to user that data for state was sent.
	std::cout << "User State " << state << " Sent" << std::endl;
	return(state);
}

string RegistrarEmployee::sendGender() { //Displays to user that data for gender was sent.
	std::cout << "User Gender " << gender << " Sent" << std::endl;
	return(gender);
}

// Method to receive all information
void RegistrarEmployee::receiveAll(const vector<string>& data) {
    if (data.size() < 8) {
        cout << "Insufficient data provided to receiveAll method." << endl;
        return;
    }

    RegistrarEmployee::recieveFName(data[0]);
    RegistrarEmployee::recieveLName(data[1]);
    RegistrarEmployee::recieveEmail(data[2]);
    RegistrarEmployee::recieveSSN(data[3]);
    RegistrarEmployee::recieveAddress(data[4]);
    RegistrarEmployee::recieveCity(data[5]);
    RegistrarEmployee::recieveState(data[6]);
    RegistrarEmployee::recieveGender(data[7]);
}

// Method to send all information
vector<string> RegistrarEmployee::sendAll() {
    RegistrarEmployee::sendFName();
    RegistrarEmployee::sendLName();
    RegistrarEmployee::sendEmail();
    RegistrarEmployee::sendSSN();
    RegistrarEmployee::sendAddress();
    RegistrarEmployee::sendCity();
    RegistrarEmployee::sendState();
    RegistrarEmployee::sendGender();
}

void RegistrarEmployee::recieveFName(string newFName) { //Inserts new fname into appropriate location.
	fName = std::move(newFName);
}

void RegistrarEmployee::recieveLName(string newLName) { //Inserts new lname into appropriate location.
	lName = std::move(newLName);
}

void RegistrarEmployee::recieveEmail(string newEmail) { //Inserts new email into appropriate location.
	email = std::move(newEmail);
}

void RegistrarEmployee::recieveSSN(string newSSN) { //Inserts new ssn into appropriate location.
	ssn = std::move(newSSN);
}

void RegistrarEmployee::recieveAddress(string newAddress) { //Inserts new address into appropriate location.
	address = std::move(newAddress);
}

void RegistrarEmployee::recieveCity(string newCity) { //Inserts new city into appropriate location.
	city = std::move(newCity);
}

void RegistrarEmployee::recieveState(string newState) { //Inserts new state into appropriate location.
	state = std::move(newState);
}

void RegistrarEmployee::recieveGender(string newGender) { //Inserts new gender into appropriate location.
	gender = std::move(newGender);
}

string RegistrarEmployee::sendToGovFName() { //Sends user data to Governemnt
	return(fName);
}

string RegistrarEmployee::sendToGovLName() { //Sends user data to Governemnt
	return(lName);
}

string RegistrarEmployee::sendToGovEmail() { //Sends user data to Governemnt
	return(email);
}

string RegistrarEmployee::sendToGovSSN() { //Sends user data to Governemnt
	return(ssn);
}

string RegistrarEmployee::sendToGovAddress() { //Sends user data to Governemnt
	return(address);
}

string RegistrarEmployee::sendToGovCity() { //Sends user data to Governemnt
	return(city);
}

string RegistrarEmployee::sendToGovState() { //Sends user data to Governemnt
	return(state);
}

string RegistrarEmployee::sendToGovZipcode() {
	return(zipcode); 
}

string RegistrarEmployee::sendToGovGender() { //Sends user data to Governemnt
	return(gender);
}

