//
// Created by Binnur on 5/28/2019.
//

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const std::string &iban, double balance, double overdraftAmount) : Account(iban,
                                                                                                            balance),
                                                                                                    overdraftAmount(
                                                                                                            overdraftAmount) {}

const double CheckingAccount::getOverdraftAmount() const {
    return overdraftAmount;
}

void CheckingAccount::withdraw(double amount)  {
    if (amount < 0) throw "amount is negative!";
    if (amount > (overdraftAmount + balance))
        throw InsufficientBalance(
                "Your balance does not cover your expenses",
                amount-balance-overdraftAmount
        );
    balance -= amount;
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account) {
    os << "CheckingAccount :: "
       << "iban:" << account.getIban()
       << ", balance:" << account.getBalance()
       << " , overdraftAmount: " << account.overdraftAmount;
    return os;
}




