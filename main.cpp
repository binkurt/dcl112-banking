#include <iostream>
#include <string>
#include "Account.h"
#include "Customer.h"
#include "CheckingAccount.h"

int main() {
    Customer jack("12345678910", "Jack Bauer");
    Account acc1("TR1", 1'000);
        acc1.withdrawAvailable(2'000);
        /*
    try {
    } catch (InsufficientBalance &e) {
        cerr << e.getDeficit() << endl;
    } catch (exception &e) {
        cerr << e.what() << endl;
    } catch (...) {
        cerr << "Something is wrong!" << endl;
    }
*/

    Account acc2("TR2", 2'000);
    Account acc3("TR3", 3'000);
    auto balance = ++acc3;
    cout << "balance: " << balance << endl;
    cout << acc3 << endl;
    jack.addAccount(acc1);
    jack.addAccount(acc2);
    jack.addAccount(acc3);
    cout << "Number of accounts: " << jack.getNumOfAccounts() << endl;
    optional<shared_ptr<Account>> acc = jack["TR200"];
    try{
       cout << (acc.value())->getIban() << endl;
    } catch (bad_optional_access &e){
        cerr << e.what() << endl;
    }
    if (acc.has_value())
       cout << (acc.value())->getIban() << endl;
    else
        cout << "Not found!" << endl;
    for (auto i = 0; i < jack.getNumOfAccounts(); ++i)
        if (jack[i].has_value())
           cout << jack[i].value()->getIban() << endl;
    CheckingAccount acc5("TR5", 5'000, 2'500);
    jack.addAccount(acc5);
    cout << jack() << endl;
    return 0;
}





