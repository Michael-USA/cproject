#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

#include "PersonInfo.h"
#include "C:/Users/jason/OneDrive/Documents/VS Tests/voter-registration/RegistrarEmployee.h"
#include "Government.h" 

using namespace std;

int main() {

	int UIChoice1;
	bool UIChoice2 = false;
	string attemptingToVote; 
	
	PersonInfo person;
	RegistrarEmployee employee;
	Government gov; 
	

	//Fills each string with empty data display.
	string fName = person.getFName();
	string lName = person.getLName();
	string email = person.getEmail();
	string ssn = person.getSSN();
	string address = person.getAddress();
	string city = person.getCity();
	string state = person.getState();
	string gender = person.getGender();

	//Displays 'empty' values Eg. (No First Name)
	/* Was used to verify system integrity. Commented out to clean up UI.
	std::cout << fName << std::endl;
	std::cout << lName << std::endl;
	std::cout << email << std::endl;
	std::cout << ssn << std::endl;
	std::cout << address << std::endl;
	std::cout << city << std::endl;
	std::cout << state << std::endl;
	std::cout << gender << std::endl;
	*/

	//Begin User Interface
	std::cout << "Thank you for choosing to participate in the voting process!\n";
	
	do {
		std::cout << "Please select the option we can help you with today by entering the corresponding number.\n";
		std::cout << "1. Register to Vote.\n2.Update existing voter information.\n";
		std::cin >> UIChoice1;

		switch(UIChoice1){
			case 1: // UI for user to input and verify personal info.
				std::cout << "Thank you for choosing to register to vote in the local Alabama election.\n";
				std::cout << "First, we need to collect some of your information.\n";
			
				//Prompts user to modify and verify each value.
				do {
					person.modifyFName();
					person.modifyLName();
					person.modifyEmail();
					person.modifySSN();
					person.modifyAddress();
					person.modifyCity(); 
					person.modifyState();
					person.modifyGender();

					//Verify voter input.
					std::cout << "Is the following information correct?\n";
					std::cout << fName << std::endl;
					std::cout << lName << std::endl;
					std::cout << email << std::endl;
					std::cout << ssn << std::endl;
					std::cout << address << std::endl;
					std::cout << city << std::endl;
					std::cout << state << std::endl;
					std::cout << gender << std::endl;
					std::cout << "Please enter the number corresponding to your choice.\n0.No\n1.Yes\n";
					std::cin, UIChoice2;
				} while (UIChoice2 == false);
				

				//Stores user input and displays final time.
				std::cout << "The following information has been stored.\n";
				fName = person.getFName();
				lName = person.getLName();
				email = person.getEmail();
				ssn = person.getSSN();
				address = person.getAddress();
				city = person.getCity();
				state = person.getState();
				gender = person.getGender();
				break;
		
			default:
				std::cout << "This is not a valid option. Please type the number corresponding to your choice. (1 or 2)\n";
		} while (UIChoice1 < 1 || UIChoice1 > 2);

	employee.recieveFName(fName);
	employee.recieveLName(lName);
	employee.recieveEmail(email);
	employee.recieveSSN(ssn);
	employee.recieveAddress(address);
	employee.recieveCity(city);
	employee.recieveState(state);
	employee.recieveGender(gender);

	employee.sendFName();
	employee.sendLName();
	employee.sendEmail();
	employee.sendSSN();
	employee.sendAddress();
	employee.sendCity();
	employee.sendState();
	employee.sendGender();

	std::cout << "Are you attempting to vote?\n"; 
	std::cout << "Enter \'n\' to quit the program"; 
	if (attemptingToVote == "n" || attemptingToVote == "N" || attemptingToVote == "No" || attemptingToVote == "NO" || attemptingToVote == "nO") {
		break; 
	}
	// validate city, state, zipcode
	// need to check for eligibility
	// if eligible, then approve
	// if approved, then update the voter database 
	gov.validate_city(employee); 
	gov.validate_state(employee); 
	gov.validate_zipcode(employee);
	gov.eligibilityCheck(); 
	gov.approveRegistration(); 
	gov.updateVoterDatabase(employee);  

} while(attemptingToVote != "n" || attemptingToVote != "N" || attemptingToVote != "No" || attemptingToVote != "NO" || attemptingToVote != "nO"); 
 std::cout << "Terminated" << std::endl; 

