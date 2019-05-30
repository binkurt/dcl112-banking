#ifndef BANKING_ACCOUNT_H
#define BANKING_ACCOUNT_H

#include <iostream>
#include <string>
#include "InsufficientBalance.h"

struct Account {
private:
    const std::string iban;
protected:
    double balance;
public:
    Account(const std::string &iban, double balance = 10.0) : iban(iban) {
        this->balance = balance;
    }

    const std::string &getIban() const {
        return iban;
    }

    double getBalance() const {
        return balance;
    }

    virtual void withdraw(double amount) ;
    virtual double withdrawAvailable(double amount);
    virtual bool deposit(double amount);

    double operator++() { // pre increment
        balance = balance + 1;
        return balance;
    }

    double operator++(int) { // post increment
        double temp = balance;
        balance = balance + 1;
        return temp;
    }
    // friend std::ostream &operator<<(std::ostream &os, const Account &account);
};

std::ostream &operator<<(std::ostream &os, const Account &account);

#endif //BANKING_ACCOUNT_H
