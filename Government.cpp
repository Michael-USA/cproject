#include "Government.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Government::Government() : approved(false), registered(false) {}

Government::~Government() = default;

bool Government::valid_city() {
    return employee.sendToGovCity() == "Mobile";
}

bool Government::valid_state() {
    string state = employee.sendToGovState();
    return state == "Alabama" || state == "AL";
}

bool Government::valid_zipcode() {
    return employee.sendToGovZipcode() == "36695"; // add more valid zip codes as needed
}

void Government::checkVoterDatabase() {
    ifstream fin("voter-registry.csv");
    string line, word;
    registered = false;

    while (getline(fin, line)) {
        stringstream s(line);
        while (getline(s, word, ',')) {
            if (word == employee.sendToGovSSN()) {
                registered = true;
                return;
            }
        }
    }
}

bool Government::eligibilityCheck() const {
    return !registered;
}

void Government::approveRegistration() {
    approved = eligibilityCheck();
}

void Government::updateVoterDatabase() {
    if (approved) {
        ofstream voterRegistry("voter-registry.csv", ios::app);
        voterRegistry << employee.sendToGovFName() << ','
                      << employee.sendToGovLName() << ','
                      << employee.sendToGovSSN() << ','
                      << employee.sendToGovEmail() << ','
                      << employee.sendToGovAddress() << ','
                      << employee.sendToGovCity() << ','
                      << employee.sendToGovState() << ','
                      << employee.sendToGovZipcode() << ','
                      << employee.sendToGovGender() << '\n';
    }
}