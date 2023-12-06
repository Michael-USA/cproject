#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "RegistrarEmployee.h"
#include "PersonInfo.h"

class Government {
private:
    bool approved;
    bool registered;
    RegistrarEmployee employee;

public:
    Government();
    ~Government();

    bool valid_city();
    bool valid_state();
    bool valid_zipcode();
    void checkVoterDatabase();
    bool eligibilityCheck() const;
    void approveRegistration();
    void updateVoterDatabase();
};

#endif // GOVERNMENT_H