#include "Account.h"
#include "Customer.h"
#include "CustomerDao.h"

int main() {
    Customer jack;
    CustomerDao::readCustomerFromFile("c:\\tmp\\jack.dat", jack);
    std::cout << jack << endl;
    return 0;
}

