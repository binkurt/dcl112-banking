#ifndef BANKING_CUSTOMERDAO_H
#define BANKING_CUSTOMERDAO_H


#include <string>
#include "Customer.h"

class CustomerDao {
public:
    static void writeCustomerToFile(const std::string &filename, const Customer &customer);

    static void readCustomerFromFile(const std::string &filename, Customer &customer);
};


#endif //BANKING_CUSTOMERDAO_H
