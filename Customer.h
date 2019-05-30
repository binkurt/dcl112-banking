#ifndef BANKING_CUSTOMER_H
#define BANKING_CUSTOMER_H

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include "Account.h"

using namespace std;

class Customer {
    const string identity;
    string fullname;
    vector<shared_ptr<Account>> accounts;
public:
    Customer(const string &identity, const string &fullname);

    const string &getIdentity() const;

    const string &getFullname() const;

    void setFullname(const string &fullname);

    void addAccount(Account &);

    optional<shared_ptr<Account>> findAccount(const string &iban) const;

    optional<shared_ptr<Account>> operator[](const string &iban) const;

     optional<shared_ptr<Account>> findAccount(int index) const;

    optional<shared_ptr<Account>> operator[](int index) const;

    double operator()() const;

    int getNumOfAccounts() const;
};


#endif //BANKING_CUSTOMER_H
