#include <fstream>
#include "CustomerDao.h"

void CustomerDao::writeCustomerToFile(const std::string &filename, const Customer &customer) {
    std::ofstream outfile(filename, ios::binary);
    outfile.write((char *) &customer, sizeof(customer));
}

void CustomerDao::readCustomerFromFile(const std::string &filename, Customer &customer) {
    ifstream infile(filename, ios::binary);
    infile.read((char *) &customer, sizeof(customer));
}
