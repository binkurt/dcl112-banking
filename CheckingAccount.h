#ifndef BANKING_CHECKINGACCOUNT_H
#define BANKING_CHECKINGACCOUNT_H


#include <ostream>
#include "Account.h"

class CheckingAccount : public Account {
    const double overdraftAmount;
public:
    CheckingAccount(const std::string &iban, double balance, double overdraftAmount);

    const double getOverdraftAmount() const;

    void withdraw(double amount) override;

    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);
};


#endif //BANKING_CHECKINGACCOUNT_H
