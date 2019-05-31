#include "Account.h"
#include "Customer.h"
#include "CustomerDao.h"

int main() {
    Customer jack("12345678910", "Jack Bauer");
    Account acc1("TR1", 1'000);
    Account acc2("TR2", 2'000);
    Account acc3("TR3", 3'000);
    jack.addAccount(acc1);
    jack.addAccount(acc2);
    jack.addAccount(acc3);
    CustomerDao::writeCustomerToFile("c:\\tmp\\jack.dat", jack);
    return 0;
}

