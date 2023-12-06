#pragma once 
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <sstream>
#include "C:/Users/jason/OneDrive/Documents/VS Tests/voter-registration/RegistrarEmployee.h"


using namespace std; 

class Government {
private: 
// string state, deptID, deptName; -- didn't get used 
bool approved;
bool registered;  
RegistrarEmployee employee; 

public:
Government(); 
~Government(); 
bool validate_city(RegistrarEmployee employee); 
bool validate_state(RegistrarEmployee employee);
bool validate_zipcode(RegistrarEmployee employee);
void checkVoterDatabase(RegistrarEmployee employee); 
bool eligibilityCheck(); 
void approveRegistration();  
void updateVoterDatabase(RegistrarEmployee employee); 
};