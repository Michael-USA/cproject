#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <limits>

#include "PersonInfo.h"
#include "RegistrarEmployee.h"
#include "Government.h" 

using namespace std;

int main() {
    int UIChoice1;
    bool UIChoice2 = false;
    string attemptingToVote;

    PersonInfo person;
    RegistrarEmployee employee;
    Government gov;

    // Initial variable declarations (values will be updated after user input)
    string fName, lName, email, ssn, address, city, state, gender;

    // User Interface
    cout << "Thank you for choosing to participate in the voting process!\n";

    do {
        cout << "Please select the option we can help you with today by entering the corresponding number.\n";
        cout << "1. Register to Vote.\n2. Update existing voter information.\n";
        cin >> UIChoice1;

        switch (UIChoice1) {
            case 1:
                cout << "Thank you for choosing to register to vote in the local Alabama election.\n";
                cout << "First, we need to collect some of your information.\n";

                do {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore once here
                    person.modifyFName();
                    person.modifyLName();
                    person.modifyEmail();
                    person.modifySSN();
                    person.modifyAddress();
                    person.modifyCity();
                    person.modifyState();
                    person.modifyGender();

                    // Update variables with latest input
                    fName = person.getFName();
                    lName = person.getLName();
                    email = person.getEmail();
                    ssn = person.getSSN();
                    address = person.getAddress();
                    city = person.getCity();
                    state = person.getState();
                    gender = person.getGender();

                    // Verify voter input
                    cout << "Is the following information correct?\n";
                    cout << fName << '\n' << lName << '\n' << email << '\n';
                    cout << ssn << '\n' << address << '\n' << city << '\n';
                    cout << state << '\n' << gender << '\n';
                    do {
                        cout << "Please enter the number corresponding to your choice.\n0. No\n1. Yes\n";
                        cin >> UIChoice2;
                        if (UIChoice2 == 0 || UIChoice2 == 1) {
                            break;
                        }
                        else {
                            cout << "Invalid choice.";
                        }
                    } while (true);
                } while (!UIChoice2);
            default:
                std::cout
                        << "This is not a valid option. Please type the number corresponding to your choice. (1 or 2)\n";
        }
    } while (UIChoice1 < 1 || UIChoice1 > 2);

    employee.receiveAll({fName, lName, email, ssn, address, city, state, gender});
    employee.sendAll();

    do {
        std::cout << "Are you attempting to vote?\n";
        std::cout << "Enter \'n\' to quit the program";
        cin >> attemptingToVote;
        std::regex pattern("^[nN](o|O)?$");  // Matches 'n', 'N', 'no', 'No', 'nO', 'NO'
        if (std::regex_match(attemptingToVote, pattern)) {
            break;
        }
        // validate city, state, zipcode
        // need to check for eligibility
        // if eligible, then approve
        // if approved, then update the voter database
        gov.valid_city();
        gov.valid_state();
        gov.valid_zipcode();
        gov.eligibilityCheck();
        gov.approveRegistration();
        gov.updateVoterDatabase();
    } while (true);
    std::cout << "Terminated" << std::endl;

}